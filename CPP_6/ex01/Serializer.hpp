#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

// Non-instantiable utility class for pointer serialization
class Serializer
{
public:
	// Data* -> uintptr_t
	static uintptr_t	serialize(Data* pointer);

	// uintptr_t -> Data*
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(Serializer const & other);
	Serializer &	operator=(Serializer const & other);
	~Serializer();
};

#endif
