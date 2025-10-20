#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
	public:
		typedef typename Container::iterator iterator;
		// Constructors and Destructors
		MutantStack(void);
		MutantStack(const MutantStack &other);
		~MutantStack(void);

		// Operators
		MutantStack &operator=(const MutantStack &other);

		// Iterators
		typename Container::iterator begin();
		typename Container::iterator end();
};

# include "MutantStack.tpp"

#endif
