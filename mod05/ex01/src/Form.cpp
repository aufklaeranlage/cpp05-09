#include "Form.hpp"

// Default constructors

Form::Form(void):
	name("Default form"), gradeToSign(1), gradeToExec(1)
{
	std::cout << "Default Form constructor called." << std::endl;
	isSigned = false;
}

Form::Form(const std::string &name, int toSign, int toExec):
	name(name), gradeToSign(toSign), gradeToExec(toExec)
{
	std::cout << "Default Form constructor called." << std::endl;
	if (toSign > 150 || toExec > 150)
		throw GradeTooLowException;
	if (toSign < 1 || toExec < 1)
		throw GradeTooHighException;
	isSigned = false;
}

// Copy constructors

Form::Form(const Form &other):
	name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	std::cout << "Copy Form constructor called." << std::endl;
	*this = other;
}

// Destructor

Form::~Form(void)
{
	std::cout << "Form destructor called." << std::endl;
}

// Assignment operator

Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	this->isSigned = other.isSigned;
	return (*this);
}

// Getters

std::string &Form::getName(void) const
{
	return (const_cast<std::string&>(name));
}

bool Form::getSignedStatus(void) const
{
	return (isSigned);
}

int Form::getGradeToSign(void) const
{
	return (gradeToSign);
}

int Form::getGradeToExec(void) const
{
	return (gradeToExec);
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form { name: " << f.getName()
		<< ", isSigned: " << f.getSignedStatus()
		<< ", gradeToSign: " << f.getGradeToSign()
		<< ", gradeToExec: " << f.getGradeToExec() << " }";
	return (out);
}

// Methods

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException;
	isSigned = true;
}
