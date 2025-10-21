#include "BitcoinExchange.hpp"

#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <stdint.h>
#include <algorithm>
#include <map>

static const short daysPerMonth[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

typedef struct s_time {
	short year;
	short month;
	short day;
	enum {
		NOERR = 0,
		EINVAL_Y,
		EINVAL_M,
		EINVAL_D,
		ERANGE_M,
		ERANGE_D
	} err;
} t_time;

static t_time getDate(std::stringstream &stream) {
	t_time time;

	time.err = t_time::NOERR;
	if (!isdigit(stream.peek()))
		return (time.err = t_time::EINVAL_Y, time);
	stream >> time.year;
	if (stream.fail() || stream.get() != '-')
		return (time.err = t_time::EINVAL_Y, time);
	stream >> time.month;
	if (stream.fail() || stream.get() != '-')
		return (time.err = t_time::EINVAL_M, time);
	stream >> time.day;
	if (stream.fail())
		return (time.err = t_time::EINVAL_D, time);
	if (time.month < 1 || time.month > 12)
		return (time.err = t_time::ERANGE_M, time);
	if (time.day < 1 || time.day > daysPerMonth[!((time.year / 100) % 4) && !(time.year % 4)][time.month - 1])
		return (time.err = t_time::ERANGE_D, time);
	return (time);
}

std::ostream &operator<<(std::ostream &out, const t_time &t) {
	switch (t.err) {
		case t_time::EINVAL_Y: std::cerr << "Invalid year"; break;
		case t_time::EINVAL_M: std::cerr << "Invalid month"; break;
		case t_time::EINVAL_D: std::cerr << "Invalid day"; break;
		case t_time::ERANGE_M: std::cerr << "Month out of range"; break;
		case t_time::ERANGE_D: std::cerr << "Day out of range"; break;
		default: out << t.year << "-" << t.month << "-" << t.day;
	}
	return (out);
}

uint64_t timeToUint64(const t_time &t) {
	uint64_t	ret;

	ret = static_cast<uint64_t>(t.year) << 10; 
	ret |= static_cast<uint64_t>(t.month) << 5; 
	ret |= static_cast<uint64_t>(t.day); 
	return (ret);
}

t_time uint64ToTime(const uint64_t t) {
	t_time	ret;

	ret.year = t >> 10;
	ret.month = t >> 5 & 31;
	ret.day = t & 31;
	ret.err = t_time::NOERR;
	return (ret);
}

static int createEntry(std::map<uint64_t, float> &m, const char *str) {
	std::stringstream stream(str);
	t_time	time;
	float	rate;

	time = getDate(stream);
	if (time.err)
		return (std::cerr << "Error: " << time << std::endl, 0);
	if (stream.get() != ',')
		return (std::cerr << "Error: Bad input after date" << std::endl, 0);
	if (!isdigit(stream.peek()))
		return (std::cerr << "Error: Extra space before value" << std::endl, 0);
	stream >> rate;
	if (stream.fail())
		return (std::cerr << "Error: Invalid rate" << std::endl, 0);
	if (rate < 0)
		return (std::cerr << "Error: Value should be positive" << std::endl, 0);
	if (!stream.eof())
		return (std::cerr << "Error: Expected newline/eof" << std::endl, 0);
	// std::cout << time << " | " << rate << std::endl;
	m[timeToUint64(time)] = rate;
	return (1);
}

void printMap(std::map<uint64_t, float> &m) {
	std::map<uint64_t, float>::iterator it, ite;
	
	it = m.begin();
	ite = m.end();
	while (it != ite) {
		std::cout << '[' << uint64ToTime(it->first) << "] = " << it->second << "; ";
		++it;
	}
	std::cout << std::endl;
}

int	readCsv(std::map<uint64_t, float> &m, const char *filename) {
	std::fstream fs;
	std::string line;

	std::cout << "Reading from: " << filename << std::endl;
	try {
		fs.open(filename, std::fstream::in);
	} catch (const std::exception &e) {
		return (std::cerr << "Caught exception: " << e.what() << "." << std::endl, 0);
	}
	getline(fs, line);
	if (line != "date,exchange_rate")
		return (std::cerr << "Improper csv format: 'date,exchange_rate' expecte ." << std::endl, 0);
	getline(fs, line);
	while (!line.empty()) {
		createEntry(m, line.c_str());
		getline(fs, line);
	}
	fs.close();
	return (1);
}

static int lookUp(std::map<uint64_t, float> &m, const char *str) {
	std::stringstream stream(str);
	t_time	time;
	char	buf[4];
	float	amount;
	float	rate;

	time = getDate(stream);
	if (time.err)
		return (std::cerr << "Error: " << time << std::endl, 0);
	stream.get(buf, 4);
	if (stream.fail() || strncmp(buf, " | ", 3))
		return (std::cerr << "Error: Bad input after date" << std::endl, 0);
	if (!isdigit(stream.peek()))
		return (std::cerr << "Error: Extra space before value" << std::endl, 0);
	stream >> amount;
	if (amount < 0)
		return (std::cerr << "Error: Value should be positive" << std::endl, 0);
	if (amount > 1000)
		return (std::cerr << "Error: Value is too large" << std::endl, 0);
	if (!stream.eof())
		return (std::cerr << "Error: Expected newline/eof" << std::endl, 0);
	// std::cout << time << " | " << amount << std::endl;
	try {
		rate = m.at(timeToUint64(time));
	} catch (const std::exception &e) {
		rate =  m.lower_bound(timeToUint64(time))->second;
	}
	std::cout << time << " => " << amount << " = " << rate * amount << std::endl;
	return (1);
}

int	readInput(std::map<uint64_t, float> &m, const char *filename) {
	std::fstream fs;
	std::string line;

	std::cout << "Reading from: " << filename << std::endl;
	try {
		fs.open(filename, std::fstream::in);
	} catch (const std::exception &e) {
		return (std::cerr << "Caught exception: " << e.what() << "." << std::endl, 0);
	}
	getline(fs, line);
	if (line != "date | value")
		return (std::cerr << "Improper csv format: 'date | value' expected ." << std::endl, 0);
	getline(fs, line);
	while (!line.empty()) {
		lookUp(m, line.c_str());
		getline(fs, line);
	}
	fs.close();
	return (1);
}
int main(int ac, char **av) {
	std::map<uint64_t, float> m;

	if (ac != 2)
		return (std::cerr << "Usage: btc <filename>" << std::endl, 1);
	if (!readCsv(m, "data.csv"))
		return (1);
	// printMap(m);
	if (!readInput(m, av[1]))
		return (1);
	return (0);
}
