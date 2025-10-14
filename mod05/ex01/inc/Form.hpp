#ifndef FORM_H
# define FORM_H

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;

		// Exceptions
		GradeTooHighExcep GradeTooHighException;
		GradeTooLowExcep GradeTooLowException;
	public:
		// Constructors and Destructors
		Form(void);
		Form(const std::string &name, int toSign, int toExec);
		Form(const Form &other);
		~Form(void);

		// Operators
		Form &operator=(const Form &other);

		// Getters
		std::string &getName(void) const;
		bool getSignedStatus(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		// Methods
		void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
