#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <exception>

class Bureaucrat {
	private:
		const std::string name;
		unsigned int grade;

		class GradeTooHighException: public std::exception {
			virtual const char *what() const throw() {
				return ("grade too high");
			}
		}	GradeTooHighException;

		class GradeTooLowException: public std::exception {
			virtual const char *what() const throw() {
				return ("grade too low");
			}
		}	GradeTooLowException;

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
		void increaseGrade();
		void decreaseGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
