#include "Time.hpp"

#include <sstream>

const short Time::daysPerMonth[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

// Default constructors

Time::Time(void)
{
	year = 0;
	month = 0;
	day = 0;
	err = NOERR;
}

// Parameterized constructors

bool Time::set(std::stringstream &stream) {
	err = NOERR;
	stream >> year;
	if (stream.fail())
		return (err = EINVAL_Y, false);
	if (stream.get() != '-')
		return (err = EINVAL_M, false);
	stream >> month;
	if (stream.fail())
		return (err = EINVAL_M, false);
	if (stream.get() != '-')
		return (err = EINVAL_D, false);
	stream >> day;
	if (stream.fail())
		return (err = EINVAL_D, false);
	if (month < 1 || month > 12)
		return (err = ERANGE_M, false);
	if (day < 1 || day > daysPerMonth[!((year / 100) % 4) && !(year % 4)][month - 1])
		return (err = ERANGE_D, false);
	return (true);
}

bool Time::set(int64_t n) {
	err = NOERR;
	year = n >> 32;
	month = n >> 16 & 65535; // 1 << 16 - 1
	day = n & 65535;
	if (month < 1 || month > 12)
		return (err = ERANGE_M, false);
	if (day < 1 || day > daysPerMonth[!((year / 100) % 4) && !(year % 4)][month - 1])
		return (err = ERANGE_D, false);
	return (true);
}

// Copy constructors

Time::Time(const Time &other)
{
	*this = other;
}

// Destructor

Time::~Time(void)
{
	
}

// Assignment operator

Time &Time::operator=(const Time &other)
{
	if (this == &other)
		return (*this);
	year = other.year;
	month = other.month;
	day = other.day;
	err = other.err;
	return (*this);
}

int64_t		Time::toInt64(void) const {
	int64_t	ret;

	ret = year;
	ret = ret << 16 | month;
	ret = ret << 16 | day;
	return (ret);
}

std::ostream &operator<<(std::ostream &out, const Time &t) {
	switch (t.err) {
		case Time::NOERR: out << t.year << "-" << t.month << "-" << t.day; break;
		case Time::EINVAL_Y: out << "Invalid year"; break;
		case Time::EINVAL_M: out << "Invalid month"; break;
		case Time::EINVAL_D: out << "Invalid day"; break;
		case Time::ERANGE_M: out << "Month out of range"; break;
		case Time::ERANGE_D: out << "Day out of range"; break;
	}
	return (out);
}
