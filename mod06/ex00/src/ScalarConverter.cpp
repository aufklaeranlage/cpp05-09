#include "ScalarConverter.hpp"

#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <limits>
#include <cmath>
#include <exception>

// Utils

static bool isPseudoLiteral(double d) {
	if (isnan(d) || isinf(d))
		return (true);
	return (false);
}

static bool isPseudoLiteral(float f) {
	if (isnan(f) || isinf(f))
		return (true);
	return (false);
}

static bool checkPrint(const char *str) {
	char *ptr;

	ptr = const_cast<char*>(str);
	while (*ptr) {
		if (!std::isprint(*ptr))
			return (false);
		++ptr;
	}
	return (true);
}

ScalarConverter::type ScalarConverter::getType(const std::string &str) {
	const int size = static_cast<int>(str.size());
	int	offset;

	if (str.empty())
		throw (InvalidLiteralException());
	offset = 0;
	while (std::isspace(str[offset]))
		++offset;
	if (size - offset == 0
		|| checkPrint(str.data() + offset) == false)
		throw (InvalidLiteralException());
	if (size - offset == 0
		|| (size - offset == 1 && !std::isdigit(str[offset])))
		return (ScalarConverter::CHAR);
	if (str[offset] == '-' || str[offset] == '+')
		++offset;
	if (!strncmp("nan", str.data() + offset, 3)
		|| !strncmp("inf", str.data() + offset, 3))
	{
		if (!strncmp("f", str.data() + offset + 3, 2))
			return (ScalarConverter::FLOAT);
		if (str[offset + 3] == '\0')
			return (ScalarConverter::DOUBLE);
		throw (InvalidLiteralException());
	}
	while (std::isdigit(str[offset]))
		++offset;
	if (str[offset] == '\0')
		return (ScalarConverter::INT);
	if (str[offset] == 'f')
		return (ScalarConverter::FLOAT);
	if (str[offset] != '.')
		throw (InvalidLiteralException());
	++offset;
	while (std::isdigit(str[offset]))
		++offset;
	if (str[offset] == '\0')
		return (ScalarConverter::DOUBLE);
	if (str[offset] == 'f')
		return (ScalarConverter::FLOAT);
	throw (InvalidLiteralException());
}

int ScalarConverter::stoi(const std::string &str, std::size_t *pos = NULL, int base = 10) {
	long l;
	char *ptr;
	char *endptr;

	errno = 0;
	ptr = const_cast<char*>(str.c_str());
	while (std::isspace(*ptr))
		++ptr;
	l = strtol(ptr, &endptr, base);
	if (errno == ERANGE || l > std::numeric_limits<int>::max() || l < std::numeric_limits<int>::min())
		throw (OutOfRangeException());
	if (l == 0 && endptr == ptr)
		throw (InvalidLiteralException());
	if (pos != NULL)
		*pos = endptr - str.c_str();
	return (static_cast<int>(l));
}

float ScalarConverter::stof(const std::string &str, std::size_t *pos = NULL) {
	float f;
	char *ptr;
	char *endptr;

	errno = 0;
	ptr = const_cast<char*>(str.c_str());
	while (std::isspace(*ptr))
		++ptr;
	if (!strncmp("inff", ptr + (*ptr == '-' || *ptr == '+'), 5))
		return ((*ptr == '-') ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity());
	if (!strncmp("nanf", ptr + (*ptr == '-' || *ptr == '+'), 4))
		return ((*ptr == '-') ? -std::numeric_limits<float>::quiet_NaN() : std::numeric_limits<float>::quiet_NaN());
	f = strtof(ptr, &endptr);
	if (errno == ERANGE)
		throw (OutOfRangeException());
	if (f == 0 && endptr == ptr)
		throw (InvalidLiteralException());
	if (pos != NULL)
		*pos = endptr - str.c_str();
	return (f);
}

double ScalarConverter::stod(const std::string &str, std::size_t *pos = NULL) {
	double d;
	char *ptr;
	char *endptr;

	ptr = const_cast<char*>(str.c_str());
	while (std::isspace(*ptr))
		++ptr;
	if (!strncmp("inf", ptr + (*ptr == '-' || *ptr == '+'), 4))
		return ((*ptr == '-') ? -std::numeric_limits<double>::infinity() : std::numeric_limits<double>::infinity());
	if (!strncmp("nan", ptr + (*ptr == '-' || *ptr == '+'), 4))
		return ((*ptr == '-') ? -std::numeric_limits<double>::quiet_NaN() : std::numeric_limits<double>::quiet_NaN());
	d = strtod(ptr, &endptr);
	if (errno == ERANGE)
		throw (OutOfRangeException());
	if (d == 0 && endptr == ptr)
		throw (InvalidLiteralException());
	if (pos != NULL)
		*pos = endptr - str.c_str();
	return (d);
}

char ScalarConverter::checkChar(char c) {
	if (!isascii(c))
		throw (NotAsciiException());
	if (!std::isprint(c))
		throw (NotPrintableException());
	return (c);
}

char ScalarConverter::toChar(int i) {
	char c;

	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		throw (OutOfRangeException());
	c = static_cast<char>(i);
	if (!isascii(c))
		throw (NotAsciiException());
	if (!std::isprint(c))
		throw (NotPrintableException());
	return (c);
}

char ScalarConverter::toChar(float f) {
	return (toChar(toInt(f)));
}

char ScalarConverter::toChar(double d) {
	return (toChar(toInt(d)));
}

int ScalarConverter::toInt(char c) {
	return (static_cast<int>(c));
}

int ScalarConverter::toInt(float f) {
	if (isPseudoLiteral(f))
		throw (PseudoLiteralException());
	if (f > static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min()))
		throw (OutOfRangeException());
	return (static_cast<int>(f));
}

int ScalarConverter::toInt(double d) {
	if (isPseudoLiteral(d))
		throw (PseudoLiteralException());
	if (d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()))
		throw (OutOfRangeException());
	return (static_cast<int>(d));
}

float ScalarConverter::toFloat(char c) {
	return (static_cast<float>(c));
}

float ScalarConverter::toFloat(int i) {
	return (static_cast<float>(i));
}

float ScalarConverter::toFloat(double d) {
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		throw (OutOfRangeException());
	return (static_cast<float>(d));
}

double ScalarConverter::toDouble(char c) {
	return (static_cast<double>(c));
}

double ScalarConverter::toDouble(int i) {
	return (static_cast<double>(i));
}

double ScalarConverter::toDouble(float f) {
	return (static_cast<double>(f));
}

void ScalarConverter::convertChar(const std::string &str) {
	char c;
	int	i;

	i = 0;
	while (std::isspace(str[i]))
		++i;
	c = str[i];
	std::cout << "Convert <char>" << std::endl;
	try {
		std::cout << "char: " << checkChar(c) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "int: " << toInt(c) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "float: " << toFloat(c) << "f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "double: " << toDouble(c) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::convertInt(const std::string &str) {
	int	i;

	try {
		i = stoi(str);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Convert <int>" << std::endl;
	try {
		std::cout << "char: " << toChar(i) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "int: " << i << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "float: " << toFloat(i) << "f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "double: " << toDouble(i) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::convertFloat(const std::string &str) {
	float f;

	try {
		f = stof(str);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Convert <float>" << std::endl;
	try {
		std::cout << "char: " << toChar(f) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "int: " << toInt(f) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "float: " << f << "f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "double: " << toDouble(f) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void ScalarConverter::convertDouble(const std::string &str) {
	double d;

	try {
		d = stod(str);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Convert <double>" << std::endl;
	try {
		std::cout << "char: " << toChar(d) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "int: " << toInt(d) << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "float: " << toFloat(d) << "f" << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "double: " << d << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void (*ScalarConverter::convertFuncs[4])(const std::string &str) = {
	&convertChar,
	&convertInt,
	&convertFloat,
	&convertDouble,
};

void ScalarConverter::convert(const std::string &str) {
	type t;

	try {
		t = getType(str);
		convertFuncs[t](str);
	} catch (const std::exception &e) {
		std::cout << "Caugth exception: " << e.what() << "." << std::endl;
	}
}

// Exceptions

const char *ScalarConverter::InvalidLiteralException::what(void) const throw () {
	return ("Invalid literal");
}

const char *ScalarConverter::PseudoLiteralException::what(void) const throw () {
	return ("Pseudo literal");
}

const char *ScalarConverter::NotAsciiException::what(void) const throw () {
	return ("Not Ascii");
}

const char *ScalarConverter::NotPrintableException::what(void) const throw () {
	return ("Not printable");
}

const char *ScalarConverter::OutOfRangeException::what(void) const throw () {
	return ("Out of range");
}
