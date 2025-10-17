#include "Array.hpp"

#include <stdexcept>

// Default constructors

template <class T>
Array<T>::Array(void)
{
	std::cout << "Default Array constructor called." << std::endl;
	arr_ = NULL;
	size_ = 0;
}

template <class T>
Array<T>::Array(const unsigned int n) {
	std::cout << "Parameterized Array constructor called." << std::endl;
	arr_ = new T[n];
	size_ = n;
}

// Copy constructors

template <class T>
Array<T>::Array(const Array<T> &other)
{
	std::cout << "Copy Array constructor called." << std::endl;
	arr_ = NULL;
	*this = other;
}

// Destructor

template <class T>
Array<T>::~Array(void)
{
	std::cout << "Array<T> destructor called." << std::endl;
	delete [] arr_;
}

// Assignment operator

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	std::cout << "Array assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	delete [] arr_;
	size_ = other.size();
	arr_ = new T[size_];
	for (unsigned int i = 0; i < size_; i++)
		arr_[i] = other[i];
	return (*this);
}

template <class T>
T &Array<T>::operator[](const unsigned int b) {
	if (b <0 || b >= size_)
		throw (Array<T>::OutOfRange());
	return (arr_[b]);
}

template <class T>
T &Array<T>::operator[](const unsigned int b) const {
	if (b <0 || b >= size_)
		throw (Array<T>::OutOfRange());
	return (arr_[b]);
}

// Methods

template <class T>
unsigned int Array<T>::size(void) const {
	return (size_);
}

template <class T>
void Array<T>::print (void) const {
	for (unsigned int i = 0; i < size_; i++) {
		std::cout << "Array[" << i << "]: " << arr_[i] << std::endl; 
	}
}

// Exceptions

template <class T>
const char *Array<T>::OutOfRange::what(void) const throw() {
	return ("Out of range");
}
