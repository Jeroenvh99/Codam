#ifndef SERIALIZER_C
# define SERIALIZER_C
# include <cstdint>
# include "Data.hpp"

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif