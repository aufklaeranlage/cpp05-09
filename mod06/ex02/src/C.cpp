#include "C.hpp"

// Default constructors

C::C(void)
{
	std::cout << "Default C constructor called." << std::endl;
}

// Copy constructors

C::C(const C &other)
{
	std::cout << "Copy C constructor called." << std::endl;
	*this = other;
}

// Destructor

C::~C(void)
{
	std::cout << "C destructor called." << std::endl;
}

// Assignment operator

C &C::operator=(const C &other)
{
	std::cout << "C assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}
