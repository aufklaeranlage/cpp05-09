#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExec;

	protected:
		// Exceptions
		class GradeTooLowException: public std::exception {
			public:
				virtual const char *what() const throw();
		} GradeTooLowException;
		class GradeTooHighException: public std::exception {
			public:
				virtual const char *what() const throw();
		} GradeTooHighException;
		class FormNotSignedException: public std::exception {
			public:
				virtual const char *what() const throw();
		} FormNotSignedException;
	public:
		// Constructors and Destructors
		AForm(void);
		AForm(const std::string &name, int toSign, int toExec);
		AForm(const AForm &other);
		virtual ~AForm(void) = 0;

		// Operators
		AForm &operator=(const AForm &other);

		// Getters
		std::string &getName(void) const;
		bool getSignedStatus(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		// Methods
		void beSigned(const Bureaucrat &b);
		void beExecuted(const Bureaucrat &executor) const;
		virtual void execute(void) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
