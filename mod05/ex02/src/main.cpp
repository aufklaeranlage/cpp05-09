#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

void showShrubbery()
{
	std::cout << "<> ShrubberyCreationForm  <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		AForm *form = new ShrubberyCreationForm("Bonsai");
		std::cout << *form << std::endl;
		std::cout << std::endl << "<><> Default constructionn  <><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			AForm *def = new ShrubberyCreationForm();
			std::cout << *def << std::endl;	
			delete def;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl << "<><> Method showcase  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			Bureaucrat alice = Bureaucrat("Alice", 1);
			formSignAndExec(form, alice);
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception for Bureaucrat: " << e.what() << std::endl;
		}
		delete form;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception for ShrubberyCreationForm: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showRobotomy()
{
	std::cout << "<> RobotomyRequestForm  <><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		AForm *form = new RobotomyRequestForm("Bonsai");
		std::cout << *form << std::endl;
		std::cout << std::endl << "<><> Default constructionn  <><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			AForm *def = new RobotomyRequestForm();
			std::cout << *def << std::endl;	
			delete def;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl << "<><> Method showcase  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			Bureaucrat alice = Bureaucrat("Alice", 1);
			formSignAndExec(form, alice);
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception for Bureaucrat: " << e.what() << std::endl;
		}
		delete form;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception for RobotomyRequestForm: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showPresidential()
{
	std::cout << "<> PresidentialPardonForm <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		AForm *form = new PresidentialPardonForm("Bonsai");
		std::cout << *form << std::endl;
		std::cout << std::endl << "<><> Default constructionn  <><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			AForm *def = new PresidentialPardonForm();
			std::cout << *def << std::endl;	
			delete def;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl << "<><> Method showcase  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			Bureaucrat alice = Bureaucrat("Alice", 1);
			formSignAndExec(form, alice);
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception for Bureaucrat: " << e.what() << std::endl;
		}
		delete form;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception for PresidentialPardonForm: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showAForm()
{
	std::cout << "<> Functionality showcase: General Form <><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		RobotomyRequestForm *form = new RobotomyRequestForm();
		std::cout << *form << std::endl;
		std::cout << std::endl << "<> Too low to sign and exec <><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			RobotomyRequestForm *cpy = new RobotomyRequestForm(*form);
			Bureaucrat steven = Bureaucrat("Steven", 73);
			formSignAndExec(cpy, steven);
			delete cpy;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << "." << std::endl;
		}
		std::cout << std::endl << "<> Too low to exec but can sign <><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			RobotomyRequestForm *cpy = new RobotomyRequestForm(*form);
			Bureaucrat michael = Bureaucrat("Michael", 46);
			formSignAndExec(cpy, michael);
			delete cpy;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << "." << std::endl;
		}
		std::cout << std::endl << "<> Can sign and exec  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		try {
			RobotomyRequestForm *cpy = new RobotomyRequestForm(*form);
			Bureaucrat alice = Bureaucrat("Alice", 1);
			formSignAndExec(cpy, alice);
			delete cpy;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << "." << std::endl;
		}
		delete form;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception for AForm: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int	main(void)
{
	showAForm();
	std::cout << std::endl;
	showShrubbery();
	std::cout << std::endl;
	showRobotomy();
	std::cout << std::endl;
	showPresidential();
}

