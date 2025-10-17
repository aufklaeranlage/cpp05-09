#ifndef SERIALIZER_H
# define SERIALIZER_H

# include "Data.hpp"

# include <iostream>
# include <stdint.h>

class Serializer {
	public:
		virtual ~Serializer(void) = 0;
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
