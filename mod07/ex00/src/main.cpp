#include "Templates.hpp"

# include <iostream>

void testInt() {
	int a = 5;
	int b = 15;
	std::cout << "<> int  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	testTemplate(a, b);
}

void testFloat() {
	float a = -5.9017234;
	float b = 1520.123;
	std::cout << "<> float  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	testTemplate(a, b);
}

void testString() {
	std::string a = "chaine1";
	std::string b = "chaine2";
	std::cout << "<> std::string  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	testTemplate(a, b);
}

int main(void) {
	testInt();
	testFloat();
	testString();
}
