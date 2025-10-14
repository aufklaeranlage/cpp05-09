#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>
#include <exception>

void initExecTooLow()
{
	std::cout << "<> Initialize with gradeToExec below 150  <><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Form f = Form("Form", 75, 151);
		std::cout << f << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void initExecTooHigh()
{
	std::cout << "<> Initialize with gradeToExec above 1  <><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Form f = Form("Form", 75, 0);
		std::cout << f << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void initSignTooLow()
{
	std::cout << "<> Initialize with gradeToExec below 150  <><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Form f = Form("Form", 151, 75);
		std::cout << f << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void initSignTooHigh()
{
	std::cout << "<> Initialize with gradeToSign above 1  <><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Form f = Form("Form", 0, 75);
		std::cout << f << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showcase()
{
	std::cout << "<> Functionality showcase <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Form jw = Form("JuicyWhip", 80, 40);
		std::cout << jw << std::endl;
		{
			std::cout << "<><> Default constructionn  <><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			Form def = Form();
			std::cout << def << std::endl;
			std::cout << "<><> Assigment operator <><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			def = jw;
			std::cout << def << std::endl;
		}
		{
			std::cout << "<><> Copy assignment  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			Form cpy = Form(jw);
			std::cout << cpy << std::endl;
		}
		std::cout << "<><> Method showcase  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		std::cout << jw << std::endl;
		try {
			Bureaucrat steven = Bureaucrat("Steven", 85);
			std::cout << steven << std::endl;
			steven.signForm(jw);
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception for Bureaucrat: " << e.what() << std::endl;
		}
		std::cout << jw << std::endl;
		try {
			Bureaucrat alice = Bureaucrat("Alice", 75);
			std::cout << alice << std::endl;
			alice.signForm(jw);
		}
		catch (const std::exception &e) {
			std::cout << "Caught exception for Bureaucrat: " << e.what() << std::endl;
		}
		std::cout << jw << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception for Form: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int	main(void)
{
	showcase();
	initExecTooHigh();
	initExecTooLow();
	initSignTooHigh();
	initSignTooLow();
}

