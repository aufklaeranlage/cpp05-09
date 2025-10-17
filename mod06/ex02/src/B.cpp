#include "B.hpp"

// Default constructors

B::B(void)
{
	std::cout << "Default B constructor called." << std::endl;
}

// Copy constructors

B::B(const B &other)
{
	std::cout << "Copy B constructor called." << std::endl;
	*this = other;
}

// Destructor

B::~B(void)
{
	std::cout << "B destructor called." << std::endl;
}

// Assignment operator

B &B::operator=(const B &other)
{
	std::cout << "B assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}
