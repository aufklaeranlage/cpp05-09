#include "Bureaucrat.hpp"

// Default constructors

Bureaucrat::Bureaucrat(void):
	name("default")
{
	std::cout << "Default Bureaucrat constructor called." << std::endl;
	this->grade = 150;
}


Bureaucrat::Bureaucrat(const std::string &name, int grade):
	name(name)
{
	std::cout << "Parameterized Bureaucrat constructor called." << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

// Copy constructors

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	name(other.name)
{
	std::cout << "Copy Bureaucrat constructor called." << std::endl;
	*this = other;
}

// Destructor

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
}

// Assignment operator

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
}

// Getter

std::string &Bureaucrat::getName(void) const
{
	return (const_cast<std::string&>(name));
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

// Methods

void Bureaucrat::increaseGrade(void)
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	--grade;
}

void Bureaucrat::decreaseGrade(void)
{
	if (150 <= grade)
		throw Bureaucrat::GradeTooLowException();
	++grade;
}

void Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << "." << std::endl;
	} catch (const std::exception &e) {
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << "Bureaucrat { name: " << b.getName() << ", grade: " << b.getGrade() << " }";
	return (out);
}

// Exceptions

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
}
