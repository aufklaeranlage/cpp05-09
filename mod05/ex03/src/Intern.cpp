#include "Intern.hpp"

// Default constructors

Intern::Intern(void)
{
	std::cout << "Default Intern constructor called." << std::endl;
}

// Copy constructors

Intern::Intern(const Intern &other)
{
	std::cout << "Copy Intern constructor called." << std::endl;
	*this = other;
}

// Destructor

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
}

// Assignment operator

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}

// Methods
// // Private

static AForm *makeShrubbery(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomy(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

static AForm *makePresidential(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

static const std::string formName[NUMFORMS] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

static AForm *(*formFunc[NUMFORMS])(const std::string &) = {
	&makeShrubbery,
	&makeRobotomy,
	&makePresidential
};

// // Public

AForm *Intern::makeForm(const std::string &form, const std::string &target) const {
	int	i;

	i = 0;
	while (i < NUMFORMS)
	{
		if (formName[i] == form)
			return (formFunc[i](target));
		++i;
	}
	throw Intern::InvalidFormNameException();
}

// Exceptions

const char *Intern::InvalidFormNameException::what() const throw() {
	return ("Invalid form name");
}

