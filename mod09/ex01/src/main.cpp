#include "RPN.hpp"

#include <iostream>

int main(int ac, char **av) {
	RPN rpn;
	int	val;

	if (ac != 2)
		return (std::cerr << "Error" << std::endl, 1);
	val = rpn.calculate(av[1]);
	if (rpn.fail())
		return (std::cerr << "Error" << std::endl, 1);
	std::cout << val << std::endl;
	return (0);
}
