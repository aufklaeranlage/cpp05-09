#ifndef SPAN_H
# define SPAN_H

# include <iostream>
# include <list>
# include <exception>

class Span {
	private:
		static const unsigned int __defaultSize__ = 10;
		std::list<int> lst;
		unsigned int filled;
		unsigned int size;

		// Exceptions
		class OutOfRange: public std::exception {
			virtual const char *what() const throw();
		};
		class NoValidSpan: public std::exception {
			virtual const char *what() const throw();
		};
	public:
		// Constructors and Destructors
		Span(void);
		Span(unsigned int N);
		Span(const Span &other);
		~Span(void);

		// Operators
		Span &operator=(const Span &other);

		// Methods
		void addNumber(int number);
		template <class InputIterator>
		void addNumbers(InputIterator first, InputIterator last) {
			try {
				while (first != last) {
					addNumber(*first);
					++first;
				}
			} catch (const std::exception &e) {
				throw (OutOfRange());
			}
		}
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		void print(void);
};

#endif
