#include "ScalarConverter.hpp"

int main(void) {
	std::string	input;

	while(true) {
		getline(std::cin, input);
		if (input == "exit")
			return (0);
		ScalarConverter::convert(input);
	}
	return (0);
}
