#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

// Default constructors

template <class T, class Container>
MutantStack<T, Container>::MutantStack(void): std::stack<T>()
{
	std::cout << "Default MutantStack constructor called." << std::endl;
}

// Copy constructors

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &other): std::stack<T>(other)
{
	std::cout << "Copy MutantStack constructor called." << std::endl;
	*this = other;
}

// Destructor

template <class T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called." << std::endl;
}

// Assignment operator

template <class T, class Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &other)
{
	std::cout << "MutantStack assignment operator called." << std::endl; 
	if (this == &other)
		return (*this);
	std::stack<T, Container>::c = other.c;
	return (*this);
}

// Iterators

template <class T, class Container>
typename Container::iterator MutantStack<T, Container>::begin(void) {
	return (std::stack<T, Container>::c.begin());
}

template <class T, class Container>
typename Container::iterator MutantStack<T, Container>::end(void) {
	return (std::stack<T, Container>::c.end());
}

#endif
