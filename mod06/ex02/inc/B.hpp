#ifndef B_H
# define B_H

# include "Base.hpp"

# include <iostream>

class B: public Base {
	public:
		// Constructors and Destructors
		B(void);
		B(const B &other);
		~B(void);

		// Operators
		B &operator=(const B &other);
};

#endif
