#include "Iter.hpp"

#include <iostream>

static void prUpper(char c) {
	if (isupper(c))
		std::cout << "Character '" << c << "' is uppercase." << std::endl;
}

static void prUpperConst(const char c) {
	if (isupper(c))
		std::cout << "Character '" << c << "' is uppercase." << std::endl;
}

void testStr() {
	std::string str = "This Is A Test";

	std::cout << "<> int  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "<><> Function without const variable  <><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	iter(str.c_str(), str.size(), prUpper);
	std::cout << "<><> Function with const variable <><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	iter(str.c_str(), str.size(), prUpperConst);
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

static void prInt(int i) {
	std::cout << "Int is : '" << i << "'." << std::endl;
}

static void prIntConst(const int i) {
	std::cout << "Int is : '" << i << "'." << std::endl;
}

void testInt() {
	int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	std::cout << "<> std::string  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "<><> Function without const variable  <><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	iter(arr, 10, prInt);
	std::cout << "<><> Function with const variable <><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	iter(arr, 10, prIntConst);
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int main(void) {
	testStr();
	testInt();
}
