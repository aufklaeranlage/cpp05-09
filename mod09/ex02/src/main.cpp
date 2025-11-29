#include "PmergeMe.hpp"

#include <cstdlib>
#include <vector>
#include <deque>
#include <iostream>
#include <ctime>

static	int	fillContainers(std::vector<int> &v, std::deque<int> &d, int ac, const char *av[]);

int	main(int ac, const char *av[]) {
	std::vector<int>	v;
	std::clock_t		vstart, vend;
	std::deque<int>		d;
	std::clock_t		dstart, dend;

	if (ac < 2)
		return (std::cerr << "Error" << std::endl, 1);
	fillContainers(v, d, ac - 1, av + 1);
	std::cout << "Before:";
	for (std::size_t i = 0; i < v.size(); i++) {
		std::cout << " " << v[i];
	}
	std::cout << std::endl;
	vstart = std::clock();
	MergeInsertionSort(v);
	vend = std::clock();
	dstart = std::clock();
	MergeInsertionSort(d);
	dend = std::clock();
	std::cout << "After:";
	for (std::size_t i = 0; i < v.size(); i++) {
		std::cout << " " << v[i];
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << ac -  1 << " elements with std::vector : " << 1000000 * static_cast<double>(vend - vstart) / CLOCKS_PER_SEC << " us" << std::endl;
	for (std::size_t i = 1; i < v.size(); i++) {
		if (v[i] < v[i - 1]) {
			std::cerr << "std::vector is not sorted!" << std::endl;
			break ;
		}
	}
	std::cout << "Time to process a range of " << ac -  1 << " elements with std::deque : " << 1000000 * static_cast<double>(dend - dstart) / CLOCKS_PER_SEC << " us" << std::endl;
	for (std::size_t i = 1; i < d.size(); i++) {
		if (d[i] < d[i - 1]) {
			std::cerr << "std::deque is not sorted!" << std::endl;
			break ;
		}
	}
	return (0);
}

static	int	fillContainers(std::vector<int> &v, std::deque<int> &d, int ac, const char *av[]) {
	char	*end;
	int		num;
	int		i;

	i = 0;
	while (i < ac) {
		num = static_cast<int>(strtol(av[i], &end, 10));
		if (end == NULL || *end != '\0')
			return (0);
		v.push_back(num);
		d.push_back(num);
		++i;
	}
	return (1);
}
