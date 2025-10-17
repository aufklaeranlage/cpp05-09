#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void checkObjectType(Base *p) {
	std::cout << "<> By pointer <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "Object type: ";
	identify(p);
	std::cout << std::endl;
	std::cout << "<> By reference <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
	std::cout << "Object type: ";
	identify(*p);
	std::cout << std::endl;
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

int main(void) {
	Base *ptr;

	for (int i = 0; i < 10; i ++) {
		ptr = generate();
		checkObjectType(ptr);
		delete (ptr);
	}
}
