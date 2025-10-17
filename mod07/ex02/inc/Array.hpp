#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>

template <class T>
class Array {
	private:
		T *arr_;
		unsigned int size_;

		// Exceptions
		class OutOfRange: public std::exception {
			virtual const char *what(void) const throw();
		};
	public:
		// Constructors and Destructors
		Array(void);
		Array(const unsigned int n);
		Array(const Array &other);
		~Array(void);

		// Operators
		Array &operator=(const Array &other);
		T &operator[](const unsigned int b);
		T &operator[](const unsigned int b) const;

		// Methods
		unsigned int size(void) const;
		void print(void) const;
};

# include "Array.tpp"

#endif
