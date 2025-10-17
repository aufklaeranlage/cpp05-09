#ifndef ITER_H
# define ITER_H

# include <stdint.h>

template <class T, typename F> void iter(T *ptr, const uint32_t size, F func) {
	for (uint32_t i = 0; i < size; i++) 
		func(ptr[i]);
}

#endif
