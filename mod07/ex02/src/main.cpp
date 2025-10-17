#include "Array.hpp"

void testInt() {
	std::cout << "<> int  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << std::endl;
	std::cout << "<><> Default Construction <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	Array<int> defArr = Array<int>();
	std::cout << std::endl;
	std::cout << "<><> Parameterized Construction <><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	Array<int> paramArr = Array<int>(5);
	for (int i = 0; i < 5; i++) {
		paramArr[i] = i * 2;
	}
	paramArr.print();
	std::cout << std::endl;
	std::cout << "<><> Copy Construction  <><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	Array<int> cpyArr = Array<int>(paramArr);
	cpyArr.print();
	std::cout << std::endl;
	std::cout << "<><><> Independant changes  <><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	for (int i = 0; i < 5; i++) {
		cpyArr[i] = i * 4;
	}
	std::cout << "Copied Array:" << std::endl;
	cpyArr.print();
	std::cout << "Original Array:" << std::endl;
	paramArr.print();
	std::cout << std::endl;
	std::cout << "<><> Copy Assignment  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	paramArr = cpyArr;
	paramArr.print();
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void testStr() {
	std::cout << "<> std::string  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	Array<std::string> arr = Array<std::string>(4);
	arr[0] = "Hello";
	arr[1] = ",";
	arr[2] = "World";
	arr[3] = "!";
	arr.print();
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int main(void) {
	testInt();
	std::cout << std::endl;
	testStr();
}
