#include "A.hpp"

// Default constructors

A::A(void)
{
	std::cout << "Default A constructor called." << std::endl;
}

// Copy constructors

A::A(const A &other)
{
	std::cout << "Copy A constructor called." << std::endl;
	*this = other;
}

// Destructor

A::~A(void)
{
	std::cout << "A destructor called." << std::endl;
}

// Assignment operator

A &A::operator=(const A &other)
{
	std::cout << "A assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}
