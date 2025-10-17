#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>

Base *generate(void) {
	int i;

	i = std::rand() % 3;
	switch (i) {
		case 0:
			return (dynamic_cast<Base*>(new A()));
		case 1:
			return (dynamic_cast<Base*>(new B()));
		case 2:
			return (dynamic_cast<Base*>(new C()));
	}
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Not a Base derived class";
}

void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
		return ;
	} catch (const std::exception &e) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
		return ;
	} catch (const std::exception &e) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
		return ;
	} catch (const std::exception &e) {
	}
	std::cout << "Not a Base derived class";
}
