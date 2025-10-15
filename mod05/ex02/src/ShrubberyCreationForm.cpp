#include "ShrubberyCreationForm.hpp"

#include <fstream>

// Default constructors

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 145, 137), target("defaultTarget_shrubbery")
{
	std::cout << "Default ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 145, 137), target(target + "_shrubbery")
{
	std::cout << "Parameterized ShrubberyCreationForm constructor called." << std::endl;
}

// Copy constructors

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other), target(other.target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called." << std::endl;
	*this = other;
}

// Destructor

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

// Assignment operator

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	return (*this);
}

// Methods

void ShrubberyCreationForm::execute(void) const {
	try {
		std::fstream fs;
		fs.open(target.c_str(), std::fstream::out | std::fstream::trunc);
		fs << "		; ; ;" << std::endl;
		fs << "       ;        ;  ;     ;;    ;" << std::endl;
		fs << "    ;                 ;         ;  ;" << std::endl;
		fs << "                    ;" << std::endl;
		fs << "                   ;                ;;" << std::endl;
		fs << "   ;          ;            ;              ;" << std::endl;
		fs << "   ;            ';,        ;               ;" << std::endl;
		fs << "   ;              'b      *" << std::endl;
		fs << "    ;              '$    ;;                ;;" << std::endl;
		fs << "   ;    ;           $:   ;:               ;" << std::endl;
		fs << " ;;      ;  ;;      *;  @):        ;   ; ;" << std::endl;
		fs << "              ;     :@,@):   ,;**:'   ;" << std::endl;
		fs << "  ;      ;,         :@@*: ;;**'      ;   ;" << std::endl;
		fs << "           ';o;    ;:(@';@*\"'  ;" << std::endl;
		fs << "   ;  ;       'bq,;;:,@@*'   ,*      ;  ;" << std::endl;
		fs << "              ,p$q8,:@)'  ;p*'      ;" << std::endl;
		fs << "       ;     '  ; '@@Pp@@*'    ;  ;" << std::endl;
		fs << "        ;  ; ;;    Y7'.'     ;  ;" << std::endl;
		fs << "                  :@):." << std::endl;
		fs << "                 .:@:'." << std::endl;
		fs << "               .::(@:.      -Sam Blumenstein-" << std::endl;
		fs << "------------------------------------------------" << std::endl;
		fs << "Thank you for visiting https://asciiart.website/" << std::endl;
		fs << "This ASCII pic can be found at" << std::endl;
		fs << "https://asciiart.website/art/3814" << std::endl;
		fs.close();
		std::cout << "Created shrubbery in: '" << target << "'." << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Caugth execption while Creating shrubbery: " << e.what() << "."<< std::endl;
	}
}
