#ifndef TEMPLATES_H
# define TEMPLATES_H

# include <iostream>

template <class T> void swap(T &a, T &b) {
	T tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template <class T> T min(T a, T b) {
	if (a < b)
		return (a);
	return (b);
}

template <class T> T max(T a, T b) {
	if (a < b)
		return (b);
	return (a);
}

template <class T> void testTemplate(T a, T b) {
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "min = " << ::min(a, b) << std::endl;
	std::cout << "max = " << ::max(a, b) << std::endl;
	::swap(a,b);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>" << std::endl;
}

#endif
