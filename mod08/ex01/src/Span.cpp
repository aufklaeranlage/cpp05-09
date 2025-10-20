#include "Span.hpp"

#include <limits.h>

// Default constructors

Span::Span(void)
{
	std::cout << "Default Span constructor called." << std::endl;
	size = __defaultSize__;
	lst = std::list<int>();
	filled = 0;
}

Span::Span(unsigned int N)
{
	std::cout << "Parameterized Span constructor called." << std::endl;
	size = N;
	lst = std::list<int>();
	filled = 0;
}

// Copy constructors

Span::Span(const Span &other)
{
	std::cout << "Copy Span constructor called." << std::endl;
	*this = other;
}

// Destructor

Span::~Span(void)
{
	std::cout << "Span destructor called." << std::endl;
}

// Assignment operator

Span &Span::operator=(const Span &other)
{
	std::cout << "Span assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	size = other.size;
	lst = other.lst;
	filled = other.filled;
	return (*this);
}

// Methods

void Span::addNumber(int number) {
	if (filled == size)
		throw (OutOfRange());
	lst.insert(std::lower_bound(lst.begin(), lst.end(), number), number);
	++filled;
}


unsigned int Span::shortestSpan(void) {
	std::list<int>::iterator it;
	unsigned int span;

	if (filled <= 1)
		throw (NoValidSpan());
	span = UINT_MAX;
	it = lst.begin();
	for (unsigned int i = 0; i < filled - 1; i++) {
		unsigned int prev;
		unsigned int curSpan;

		prev = *it;
		++it;
		curSpan = *it - prev;
		if (curSpan < span)
			span = curSpan;
	}
	return (span);
}

unsigned int Span::longestSpan(void) {
	if (filled <= 1)
		throw (NoValidSpan());
	return (lst.back() - lst.front());
}

void Span::print(void) {
	std::list<int>::iterator it;

	std::cout << "Span: { size: " << size << ", filled: " << filled
	<< ", lst: { ";
	it = lst.begin();
	for (unsigned int i = 0; i < filled; ++i) {
		std::cout << "[" << i << "] " << *it << " ";
		++it;
	}
	std::cout << "} }" << std::endl;
}

// Exceptions

const char *Span::OutOfRange::what(void) const throw () {
	return ("Out of range");
}

const char *Span::NoValidSpan::what(void) const throw () {
	return ("No valid span");
}
