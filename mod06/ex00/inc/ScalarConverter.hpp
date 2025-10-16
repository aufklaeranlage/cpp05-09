#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>

class ScalarConverter {
private:
		enum type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
		};

		static void (*convertFuncs[4])(const std::string &str);

		// Methods
		static type getType(const std::string &str);
		static char checkChar(char c);

		// // protected Converters
		static int stoi(const std::string &str, size_t *pos, int base);
		static float stof(const std::string &str, size_t *pos);
		static double stod(const std::string &str, size_t *pos);

		// // toChar
		static char toChar(int i);
		static char toChar(float f);
		static char toChar(double d);

		// // toInt
		static int toInt(char c);
		static int toInt(float f);
		static int toInt(double d);

		// // toFloat
		static float toFloat(char c);
		static float toFloat(int i);
		static float toFloat(double d);

		// // toDouble
		static double toDouble(char c);
		static double toDouble(int i);
		static double toDouble(float f);

		// Conversions
		static void convertChar(const std::string &str);
		static void convertInt(const std::string &str);
		static void convertFloat(const std::string &str);
		static void convertDouble(const std::string &str);

		// Exceptions
		class InvalidLiteralException: public std::exception {
			virtual const char *what(void) const throw();
		};
		class PseudoLiteralException: public std::exception {
			virtual const char *what(void) const throw();
		};
		class NotAsciiException: public std::exception {
			virtual const char *what(void) const throw();
		};
		class NotPrintableException: public std::exception {
			virtual const char *what(void) const throw();
		};
		class OutOfRangeException: public std::exception {
			virtual const char *what(void) const throw();
		};

	public:

		// Methods
		static void convert(const std::string &str);
};

#endif
