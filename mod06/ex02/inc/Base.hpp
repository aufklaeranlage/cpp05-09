#ifndef BASE_H
# define BASE_H

# include <iostream>

class Base {
	public:
		// Constructors and Destructors
		virtual ~Base(void);
};

// Associated functions

Base *generate(void);

void identify(Base *p);

void identify(Base &p);

#endif
