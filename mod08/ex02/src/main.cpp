#include "MutantStack.hpp"

#include <list>

void showList(void) {
	std::cout << "<> List <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showStack(void) {
	std::cout << "<> Stack  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "<> General Fucntionality  <><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "<><> Dafault construction and data input  <><><><><><><><><><><><><><><><><><><>" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it < mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "<><> Copy Constructor <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	MutantStack<int> cpy = mstack;
	for (MutantStack<int>::iterator it = cpy.begin(); it < cpy.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "<><> top()  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << std::endl;
	std::cout << "<><> pop() and comparison to copy <><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	mstack.pop();
	std::cout << "top: " << mstack.top() << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it < mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for (MutantStack<int>::iterator it = cpy.begin(); it < cpy.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "<><> Copy assignment  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	cpy = mstack;
	for (MutantStack<int>::iterator it = cpy.begin(); it < cpy.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int	main(void) {
	showStack();
	showList();
}
