#include "Bureaucrat.hpp"

#include <iostream>
#include <exception>

void initTooHigh()
{
	std::cout << "<> Initialize with a grade above 1  <><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Bureaucrat alice = Bureaucrat("Alice", 0);
		std::cout << alice << std::endl;
		alice.increaseGrade();
		std::cout << alice << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void initTooLow()
{
	std::cout << "<> Initialize with a grade below 150  <><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Bureaucrat steven = Bureaucrat("Steven", 151);
		std::cout << steven << std::endl;
		steven.decreaseGrade();
		std::cout << steven << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void incBelow1()
{
	std::cout << "<> Increase grade below 1 <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Bureaucrat alice = Bureaucrat("Alice", 1);
		std::cout << alice << std::endl;
		alice.increaseGrade();
		std::cout << alice << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void decAbove150()
{
	std::cout << "<> Decrease grade above 150 <><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Bureaucrat steven = Bureaucrat("Steven", 150);
		std::cout << steven << std::endl;
		steven.decreaseGrade();
		std::cout << steven << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showcase()
{
	std::cout << "<> Functionality showcase <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "<><> Parameterized construction <><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	try {
		Bureaucrat alice = Bureaucrat("Alice", 75);
		std::cout << alice << std::endl;
		{
			std::cout << "<><> Default construction <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			Bureaucrat def = Bureaucrat();
			std::cout << def << std::endl;
			std::cout << "<><> Assignment operator  <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			def = alice;
			std::cout << def << std::endl;
		}
		{
			std::cout << "<><> Copy assignment  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
			Bureaucrat cpy = Bureaucrat(alice);
			std::cout << cpy << std::endl;
		}
		std::cout << "<><> Method showcase  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		alice.increaseGrade();
		std::cout << alice << std::endl;
		alice.decreaseGrade();
		std::cout << alice << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int	main(void)
{
	initTooHigh();
	initTooLow();
	incBelow1();
	decAbove150();
	showcase();
}
