#ifndef A_H
# define A_H

# include "Base.hpp"

# include <iostream>

class A: public Base {
	public:
		// Constructors and Destructors
		A(void);
		A(const A &other);
		~A(void);

		// Operators
		A &operator=(const A &other);
};

#endif
