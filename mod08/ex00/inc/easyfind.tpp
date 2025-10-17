#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	return(find(container.begin(), container.end(), n));
}

#endif
