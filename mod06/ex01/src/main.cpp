#include "Serializer.hpp"

void printData(const Data &d) {
	std::cout << "Data: { version " << d.version << ", info: " << d.info << " }";
}

int main(void) {
	Data src = Data("v2.0.45.12", "Data container to be serialized");
	uintptr_t ptr;
	Data *cpy;

	printData(src);
	std::cout << std::endl;
	ptr = Serializer::serialize(&src);
	std::cout << "Pointer: " << ptr << std::endl;
	cpy = Serializer::deserialize(ptr);
	printData(*cpy);
	std::cout << std::endl;
	std::cout << &src << " == " << cpy << std::endl;
}
