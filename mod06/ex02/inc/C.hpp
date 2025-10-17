#ifndef C_H
# define C_H

# include "Base.hpp"

# include <iostream>

class C: public Base {
	public:
		// Constructors and Destructors
		C(void);
		C(const C &other);
		~C(void);

		// Operators
		C &operator=(const C &other);
};

#endif
