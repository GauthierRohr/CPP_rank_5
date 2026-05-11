#include "Serializer.hpp"

// Convertit un pointeur Data* en uintptr_t via reinterpret_cast.
// Retourne la valeur entière de l'adresse mémoire du pointeur.
uintptr_t	Serializer::serialize(Data* pointer)
{
	return (reinterpret_cast<uintptr_t>(pointer));
	// raw : adresse mémoire de pointer exprimée en entier non signé
}

// Convertit un uintptr_t en pointeur Data* via reinterpret_cast.
// Retourne le pointeur reconstruit depuis la valeur entière de l'adresse.
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
	// pointeur : adresse mémoire reconstituée depuis l'entier raw
}
