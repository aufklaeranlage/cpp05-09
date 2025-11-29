#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <iterator>
# include <vector>
# include <deque>

# include "MergeInsertionChain.hpp"

template <class Value, template <class, class> class Container>
void	MergeInsertionSort(Container<Value, typename std::allocator<Value> > &c) {
	Container<MergeInsertionChain<Value>, typename std::allocator<MergeInsertionChain<Value> > >	chains;
	Container<Value, std::allocator<Value> > 			sorted;
	std::size_t	size = c.size();

	chains.resize(size);
	for (std::size_t i = 0; i < size; i++) {
		chains[i].setValue(&c[i]);
	}
	sorted.resize(size);
	MergeInsertionSort_impl(chains);
	for (std::size_t i = 0; i < size; i++) {
		sorted[i] = *chains[i].value();
	}
	c = sorted;
}

template <class Value, template <class, class> class Container>
void	MergeInsertionSort_impl(Container<MergeInsertionChain<Value>, typename std::allocator<MergeInsertionChain<Value> > > &c) {
	static const std::size_t	jacobsthal_seq[] = {
		0u, 1u, 1u, 3u, 5u, 11u, 21u, 43u, 85u, 171u, 341u, 683u, 1365u, 2731u, 5461u, 10923u, 21845u, 43691u, 87381u, 174763u, 349525u, 699051u, 1398101u, 2796203u, 5592405u, 11184811u, 22369621u, 44739243u, 89478485u, 178956971u, 357913941u, 715827883u, 1431655765u, 2863311531u, 5726623061u, 11453246123
	};

	Container<MergeInsertionChain<Value>, typename std::allocator<MergeInsertionChain<Value> > >	chains;
	std::size_t	size = c.size(), psize = size / 2;

	if (size < 2)
		return ;
	chains.resize(psize);
	for (std::size_t i = 0; i < psize; i++) {
		if (*c[i * 2].value() < *c[i * 2 + 1].value()) {
			chains[i].setMain(&c[i * 2 + 1]);
			chains[i].setPend(&c[i * 2]);
		} else {
			chains[i].setMain(&c[i * 2]);
			chains[i].setPend(&c[i * 2 + 1]);
		}
	}
	MergeInsertionSort_impl(chains);
	
	Container<MergeInsertionChain<Value>, typename std::allocator<MergeInsertionChain<Value> > >	sorted;
	std::size_t	seq = 3, lower = 1, upper, lim;
	sorted.push_back(*chains[0].pend());
	sorted.push_back(*chains[0].main());
	while (lower < psize) {
		upper = jacobsthal_seq[seq++];
		lim = std::min(upper, psize);
		for (std::size_t i = lower; i + 1 < lim; i++) {
			sorted.push_back(*chains[i].main());
		}
		std::size_t insertionLim = sorted.size();
		for (std::size_t i = lim - 1; i >= lower; i--) {
			sorted.insert(
				std::lower_bound(sorted.begin(), sorted.begin() + insertionLim, *chains[i].pend(), typename MergeInsertionChain<Value>::less()), 
				*chains[i].pend());
		}
		sorted.push_back(*chains[lim - 1].main());
		lower = upper;
	}
	if (sorted.size() < size) {
		sorted.insert(
			std::lower_bound(sorted.begin(), sorted.end(), c.back(), typename MergeInsertionChain<Value>::less()), 
			c.back());
	}
	c = sorted;
}

#endif
