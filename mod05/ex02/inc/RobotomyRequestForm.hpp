#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <iostream>

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		const std::string target;
	public:
		// Constructors and Destructors
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		// Operators
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		// Methods
		void execute(void) const;
};

#endif
