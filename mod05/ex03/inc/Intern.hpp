#ifndef INTERN_H
# define INTERN_H

# include <iostream>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		// Exceptions
		class InvalidFormNameException: public std::exception {
			virtual const char *what(void) const throw();
		};
	public:
		// Constructors and Destructors
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);

		// Operators
		Intern &operator=(const Intern &other);

		// Methods
		AForm *makeForm(const std::string &form, const std::string &target) const;
};

#endif
