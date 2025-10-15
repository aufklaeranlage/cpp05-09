#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <iostream>

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		const std::string target;
	public:
		// Constructors and Destructors
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		// Operators
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		// Methods
		void execute(void) const;
};

#endif
