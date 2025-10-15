#include "PresidentialPardonForm.hpp"

// Default constructors

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5), target("defaultTarget")
{
	std::cout << "Default PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "Default PresidentialPardonForm constructor called." << std::endl;
}

// Copy constructors

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other), target(other.target)
{
	std::cout << "Copy PresidentialPardonForm constructor called." << std::endl;
	*this = other;
}

// Destructor

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

// Assignment operator

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}

// Methods

void PresidentialPardonForm::execute(void) const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
