#include "Span.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

void showcase() {
	std::cout << "<> General Functionality  <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "<><> Paramerterized construction  <><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	Span sp = Span(10);
	sp.print();
	std::cout << std::endl;
	std::cout << "<><> Adding numbers <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	for (int i = 0; i < 10; i++) {
		sp.addNumber(std::rand() % 100);
	}
	sp.print();
	{
	std::cout << std::endl;
		std::cout << "<><> Copy construction  <><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		Span cpy = sp;
		cpy.print();
	}
	{
	std::cout << std::endl;
		std::cout << "<><> Default construction <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		Span def = Span();
		for (int i = 0; i < 10; i++) {
			def.addNumber(-(std::rand() % 100));
		}
		def.print();
	std::cout << std::endl;
		std::cout << "<><> Copy assignement <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		def = sp;
		def.print();
	}
	{
	std::cout << std::endl;
		std::cout << "<><> Methods  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	try {
	std::cout << std::endl;
		std::cout << "<><> Exceptions: addNumber()  <><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		sp.addNumber(100);
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	{
	std::cout << std::endl;
		std::cout << "<><> Exceptions: No valid Span  <><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		Span def;
		def.print();
		try {
			std::cout << "Shortest span: " << def.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << def.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		def.addNumber(1);
		def.print();
		try {
			std::cout << "Shortest span: " << def.shortestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << def.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showRand() {
	Span sp = Span(20000);

	std::cout << std::endl;
	std::cout << "<> Span <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	for (int i = 0; i < 20000; i++) {
		sp.addNumber(std::rand());
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showRange() {
	Span sp = Span(10);
	std::list<int> vec;
	vec.push_back(2);
	vec.push_back(30);
	vec.push_back(45);
	vec.push_back(0);
	vec.push_back(6);
	vec.push_back(100);

	std::cout << std::endl;
	std::cout << "<> List iterator range  <><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	sp.addNumbers(vec.begin(), vec.end());
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	sp.print();
	Span ex = Span(4);
	try {
	std::cout << std::endl;
		std::cout << "<><> Exceptions: addNumbers() <><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
		ex.addNumbers(vec.begin(), vec.end());
	} catch (const std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	ex.print();
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int main(void) {
	showcase();
	showRange();
	showRand();
}
