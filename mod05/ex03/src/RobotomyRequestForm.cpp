#include "RobotomyRequestForm.hpp"

#include <stdlib.h>

// Default constructors

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", 72, 45), target("defaultTarget")
{
	std::cout << "Default RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "Default RobotomyRequestForm constructor called." << std::endl;
}

// Copy constructors

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other), target(other.target)
{
	std::cout << "Copy RobotomyRequestForm constructor called." << std::endl;
	*this = other;
}

// Destructor

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

// Assignment operator

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}

// Methods

void RobotomyRequestForm::execute(void) const {
	if (rand() % 2)
		std::cout << "RAT-A-TAT BANG BANG BANG RAT CLANG --- " << target << " has been robotomized." << std::endl;
	else
		std::cout << "Failed to robotomized " << target << "." << std::endl;
}
