#include "AForm.hpp"

// Default constructors

AForm::AForm(void):
	name("Default form"), gradeToSign(1), gradeToExec(1)
{
	std::cout << "Default AForm constructor called." << std::endl;
	isSigned = false;
}

AForm::AForm(const std::string &name, int toSign, int toExec):
	name(name), gradeToSign(toSign), gradeToExec(toExec)
{
	std::cout << "Default AForm constructor called." << std::endl;
	if (toSign > 150 || toExec > 150)
		throw AForm::GradeTooLowException();
	if (toSign < 1 || toExec < 1)
		throw AForm::GradeTooHighException();
	isSigned = false;
}

// Copy constructors

AForm::AForm(const AForm &other):
	name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec)
{
	std::cout << "Copy AForm constructor called." << std::endl;
	*this = other;
}

// Destructor

AForm::~AForm(void)
{
	std::cout << "AForm destructor called." << std::endl;
}

// Assignment operator

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	this->isSigned = other.isSigned;
	return (*this);
}

// Getters

std::string &AForm::getName(void) const
{
	return (const_cast<std::string&>(name));
}

bool AForm::getSignedStatus(void) const
{
	return (isSigned);
}

int AForm::getGradeToSign(void) const
{
	return (gradeToSign);
}

int AForm::getGradeToExec(void) const
{
	return (gradeToExec);
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm { name: " << f.getName()
		<< ", isSigned: " << f.getSignedStatus()
		<< ", gradeToSign: " << f.getGradeToSign()
		<< ", gradeToExec: " << f.getGradeToExec() << " }";
	return (out);
}

// Methods

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

void AForm::beExecuted(const Bureaucrat &b) const {
	if (getSignedStatus() == false)
		throw AForm::FormNotSignedException();
	if (b.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	execute();
}

// Exceptions

const char *AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
}

const char *AForm::FormNotSignedException::what(void) const throw() {
	return ("Form is not signed");
}
