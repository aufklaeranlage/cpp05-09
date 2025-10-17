#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <set>
#include <list>

static std::vector<int> ref;

void showVec() {
	std::cout << "<> std::vector  <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::vector<int> con(ref.begin(), ref.end());
	for (int i = -3; i < 6; i++) {
		std::vector<int>::iterator it = easyfind(con, i);
		std::cout << "Find " << i << ": ";
		if (it == con.end())
			std::cout << "Not in container";
		else
			std::cout << *it;
		std::cout << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showSet() {
	std::cout << "<> std::set <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::set<int> con(ref.begin(), ref.end());
	for (int i = -3; i < 6; i++) {
		std::set<int>::iterator it = easyfind(con, i);
		std::cout << "Find " << i << ": ";
		if (it == con.end())
			std::cout << "Not in container";
		else
			std::cout << *it;
		std::cout << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

void showList() {
	std::cout << "<> std::set <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::list<int> con(ref.begin(), ref.end());
	for (int i = -3; i < 6; i++) {
		std::list<int>::iterator it = easyfind(con, i);
		std::cout << "Find " << i << ": ";
		if (it == con.end())
			std::cout << "Not in container";
		else
			std::cout << *it;
		std::cout << std::endl;
	}
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int main(void) {
	ref = std::vector<int>(4);
	for (int i = 0; i < 4; i++) {
		ref[i] = (i * 2) - 2;
	}
	showVec();
	showSet();
	showList();
}
