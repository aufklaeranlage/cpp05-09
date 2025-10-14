#include "GradeExceptions.hpp"

const char *GradeTooHighExcep::what() const throw()
{
	return ("Grade too high");
}

const char *GradeTooLowExcep::what() const throw()
{
	return ("Grade too low");
}
