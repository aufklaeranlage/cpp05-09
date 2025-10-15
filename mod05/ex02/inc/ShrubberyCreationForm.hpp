#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		const std::string target;
	public:
		// Constructors and Destructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		// Operators
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		// Methods
		void execute(void) const;
};

#endif
