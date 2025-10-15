#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <iostream>
#include <exception>

void formSignAndExec(AForm *form, Bureaucrat &b)
{
	std::cout << b << ", " << *form << std::endl;
	std::cout << std::endl << "<><><> Sign form  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	b.signForm(*form);
	std::cout << b << ", " << *form << std::endl;
	std::cout << std::endl << "<><><> Execute form <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	b.executeForm(*form);
	std::cout << b << ", " << *form << std::endl;
}

void showIntern()
{
	std::cout << "<> Functionality showcase: Intern <><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Intern intern;
		Bureaucrat alice = Bureaucrat("Alice", 1);
		try {
			std::cout << std::endl << "<><> Shrubbery  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			AForm *f = intern.makeForm("shrubbery creation", "Bonsai");
			formSignAndExec(f, alice);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << "." << std::endl;
		}
		try {
			std::cout << std::endl << "<><> Robotomy <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			AForm *f = intern.makeForm("robotomy request", "Steven");
			formSignAndExec(f, alice);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << "." << std::endl;
		}
		try {
			std::cout << std::endl << "<><> Presidential <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			AForm *f = intern.makeForm("presidential pardon", "Fritz-Ferdinand");
			formSignAndExec(f, alice);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << "." << std::endl;
		}
		try {
			std::cout << std::endl << "<><> Non Existent <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			AForm *f = intern.makeForm("non existent", "Fritz-Ferdinand");
			formSignAndExec(f, alice);
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << "." << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << "." << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int	main(void)
{
	showIntern();
}

