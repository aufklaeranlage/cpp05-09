#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>

# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		unsigned int grade;

		// Exceptions
		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		} GradeTooLowException;
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what(void) const throw();
		} GradeTooHighException;
	public:
		// Constructors and Destructors
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);

		// Operators
		Bureaucrat &operator=(const Bureaucrat &other);

		// Getter
		std::string &getName(void) const;
		int getGrade(void) const;

		// Methods
		void increaseGrade(void);
		void decreaseGrade(void);
		void signForm(AForm &f);
		void executeForm(const AForm &f) const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
