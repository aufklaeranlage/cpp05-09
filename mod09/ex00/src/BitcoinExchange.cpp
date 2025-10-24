#include "BitcoinExchange.hpp"

#include "Time.hpp"

#include <fstream>
#include <cstring>
#include <float.h>

// Default constructors

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "Default BitcoinExchange constructor called." << std::endl;
}

// Copy constructors

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "Copy BitcoinExchange constructor called." << std::endl;
	*this = other;
}

// Destructor

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called." << std::endl;
}

// Assignment operator

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}

// Methods

bool BitcoinExchange::storeEntry(const char *line) {
	std::stringstream	stream(line);
	Time				t;
	double				val;

	if (!t.set(stream))
		return (std::cerr << "Error: " << t << std::endl, false);
	if (stream.get() != ',')
		return (std::cerr << "Error: Bad input after date" << std::endl, false);
	if (!isdigit(stream.peek()))
		return (std::cerr << "Error: Extra space before value" << std::endl, false);
	stream >> val;
	if (stream.fail())
		return (std::cerr << "Error: Invallid rate" << std::endl, false);
	if (val < 0)
		return (std::cerr << "Error: Rate value should be positive" << std::endl, false);
	if (!stream.eof())
		return (std::cerr << "Error: Expected newline/eof" << std::endl, false);
	return (m[t.toInt64()] = val);
}

bool	BitcoinExchange::readCsv(const char *filename) {
	std::fstream fs;
	std::string line;

	fs.open(filename, std::fstream::in);
	if (fs.fail())
		return (std::cerr << "Error: Couldn't open file '" << filename << "'" << std::endl, false);
	getline(fs, line);
	if (line != "date,exchange_rate")
		return (std::cerr << "Error: Improper csv format: 'date,exchange_rate' expected." << std::endl, false);
	getline(fs, line);
	while (!line.empty()) {
		storeEntry(line.c_str());
		getline(fs, line);
	}
	fs.close();
	return (true);
}

void	BitcoinExchange::printMap(void) {
	std::map<int64_t, double>::iterator it, ite;
	Time								t;
	
	it = m.begin();
	ite = m.end();
	while (it != ite) {
		t.set(it->first);
		std::cout << '[' << t << "] = " << it->second << "; ";
		++it;
	}
	std::cout << std::endl;
}

bool BitcoinExchange::readInput(const char *filename) {
	std::fstream fs;
	std::string line;

	std::cout << "Reading from: " << filename << std::endl;
	fs.open(filename, std::fstream::in);
	if (fs.fail())
		return (std::cerr << "Error: Couldn't open file '" << filename << "'" << std::endl, false);
	getline(fs, line);
	if (line != "date | value")
		return (std::cerr << "Improper input format: 'date | value' expected ." << std::endl, false);
	getline(fs, line);
	while (!line.empty()) {
		lookUp(line.c_str());
		getline(fs, line);
	}
	fs.close();
	return (true);
}

static double	upperBound(std::map<int64_t, double> &m, int64_t t) {
	std::map<int64_t, double>::iterator	it;
	
	it = m.lower_bound(t);
	return ((it != m.begin()) ? (--it)->second : it->second);
}

void	BitcoinExchange::lookUp(const char *line) {
	std::stringstream stream(line);
	Time	t;
	char	buf[4];
	double	amount;
	double	rate;

	if (!t.set(stream))
	{ std::cerr << "Error: " << t << std::endl; return ; }
	stream.get(buf, 4);
	if (stream.fail() || strncmp(buf, " | ", 3))
	{ std::cerr << "Error: Bad separator" << std::endl; return ; }
	if (!isdigit(stream.peek()))
	{ std::cerr << "Error: Extra space after separator" << std::endl; return ; }
	stream >> amount;
	if (amount < 0)
	{ std::cerr << "Error: Value should be positive" << std::endl; return ; }
	if (amount > 1000)
	{ std::cerr << "Error: Value is too large" << std::endl; return ; }
	if (!stream.eof())
	{ std::cerr << "Error: Expected newline/eof" << std::endl; return ; }
	try {
		rate = m.at(t.toInt64());
	} catch (const std::exception &e) {
		rate = upperBound(m, t.toInt64());
	}
	if (amount != 0 && DBL_MAX / (double)amount < rate)
	{ std::cerr << "Error: Int64 overflow on rate * amount" << std::endl; return ; }
	std::cout << t << " => " << amount << " = " << rate * amount << std::endl;
}
