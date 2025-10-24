#include "RPN.hpp"

#include <limits.h>
#include <sstream>

// Default constructors

RPN::RPN(void)
{
	std::cout << "Default RPN constructor called." << std::endl;
}

// Copy constructors

RPN::RPN(const RPN &other)
{
	std::cout << "Copy RPN constructor called." << std::endl;
	*this = other;
}

// Destructor

RPN::~RPN(void)
{
	std::cout << "RPN destructor called." << std::endl;
}

// Assignment operator

RPN &RPN::operator=(const RPN &other)
{
	std::cout << "RPN assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	st = other.st;
	err = other.err;
	return (*this);
}

// Methods

int	RPN::add(void) {
	int a;
	int b;

	b = st.top();
	st.pop();
	a = st.top();
	st.pop();
	if ((a < 0 && b < INT_MIN - a) || (a > 0 && b > INT_MAX - a))
		return (err = 1, 0);
	return (a + b);
}

int	RPN::sub(void) {
	int a;
	int b;

	b = st.top();
	st.pop();
	a = st.top();
	st.pop();
	if ((a < 0 && b > -(INT_MIN - a)) || (a > 0 && b < -(INT_MAX - a)))
		return (err = 1, 0);
	return (a - b);
}

int	RPN::mul(void) {
	int a;
	int b;

	b = st.top();
	st.pop();
	a = st.top();
	st.pop();
	if (a != 0 &&
		((a < 0 && (b > INT_MIN / a ||
		b < INT_MAX / a)) ||
		(a > 0 && (b < INT_MIN / a ||
		b > INT_MAX / a))))
		return (err = 1, 0);
	return (a * b);
}

int	RPN::div(void) {
	int a;
	int b;

	b = st.top();
	st.pop();
	a = st.top();
	st.pop();
	if (b == 0)
		return (err = 1, 0);
	return (a / b);
}

const char	RPN::calcFuncSymbols[5] = "+-*/";

int	RPN::calc(char c) {
	switch (numOp(c)) {
		case 0: return (add());
		case 1: return (sub());
		case 2: return (mul());
		case 3: return (div());
	}
	return (err = 1, 0);
}

bool RPN::isOp(char c) {
	int	i;

	i = 0;
	while (i < 4) {
		if (calcFuncSymbols[i] == c)
			return (true);
		++i;
	}
	return (false);
}

int RPN::numOp(char c) {
	int	i;

	i = 0;
	while (i < 4) {
		if (calcFuncSymbols[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

int RPN::calculate(const char *str) {
	std::stringstream stream(str);
	int		continousDigits;
	char	c;

	err = 0;
	continousDigits = 0;
	while (!err) {
		stream >> c;
		if (stream.fail() || (stream.get() != ' ' && !stream.eof()))
			return (err = 1, 0);
		if (isdigit(c)) {
			st.push(c - '0');
			++continousDigits;
			if (continousDigits > 2)
				return (err = 1, 0);
		} else if (isOp(c)) {
			if (st.size() < 2)
				return (err = 1, 0);
			st.push(calc(c));
			continousDigits = 0;
		} else {
			return (err = 1, 0);
		}
		if (stream.eof())
			break ;
	}
	if (st.size() > 1)
		return (err = 1, 0);
	return (st.top());
}

bool RPN::fail(void) const {
	return (err != 0);
}
