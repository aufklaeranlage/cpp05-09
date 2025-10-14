#ifndef GRADEEXCEPTIONS_H
# define GRADEEXCEPTIONS_H

# include <exception>

class GradeTooHighExcep: public std::exception {
	virtual const char *what() const throw();
};

class GradeTooLowExcep: public std::exception {
	virtual const char *what() const throw();
};

#endif
