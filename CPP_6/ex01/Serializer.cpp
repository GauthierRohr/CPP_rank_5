#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(Serializer const &) {}
Serializer& Serializer::operator=(Serializer const &) { return *this; }
Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* pointer)
{
	return (reinterpret_cast<uintptr_t>(pointer));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
