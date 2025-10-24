#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	BitcoinExchange	be;

	if (ac != 2)
		return (std::cout << "Usage: btc <filename>" << std::endl, 0);
	if (!be.readCsv("data.csv"))
		return (1);
	if (!be.readInput(av[1]))
		return (1);
	return (0);
}
