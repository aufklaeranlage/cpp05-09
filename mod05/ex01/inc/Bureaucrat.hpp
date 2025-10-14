#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>

# include "GradeExceptions.hpp"
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string name;
		unsigned int grade;

		GradeTooHighExcep GradeTooHighException;
		GradeTooLowExcep GradeTooLowException;

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
		void signForm(Form &f);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
