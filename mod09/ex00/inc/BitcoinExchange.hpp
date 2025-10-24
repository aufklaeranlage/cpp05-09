#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# include <iostream>
# include <stdint.h>
# include <map>

class BitcoinExchange {
private:
	std::map<int64_t, double> m;

public:
	// Constructors and Destructors
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	~BitcoinExchange(void);

	// Operators
	BitcoinExchange &operator=(const BitcoinExchange &other);

	// Methods
	bool	storeEntry(const char *line);
	bool	readCsv(const char *filename);
	void	printMap(void);
	void	lookUp(const char *line);
	bool	readInput(const char *filename);
};

#endif
