#ifndef DATA_H
# define DATA_H

# include <iostream>

struct Data {
	public:
		std::string version;
		std::string info;

		// Constructors and Destructors
		Data(void);
		Data(const std::string &version, const std::string &info);
		Data(const Data &other);
		~Data(void);

		// Operators
		Data &operator=(const Data &other);
};

#endif
