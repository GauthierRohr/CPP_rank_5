#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

// Classe utilitaire de sérialisation/désérialisation de pointeur.
// Non instanciable : constructeur et opérateur d'affectation privés.
class Serializer
{
public:
	// Convertit un pointeur Data* en entier non signé (sérialisation).
	static uintptr_t	serialize(Data* pointer);

	// Convertit un entier non signé en pointeur Data* (désérialisation).
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(Serializer const & other);
	Serializer &	operator=(Serializer const & other);
	~Serializer();
};

#endif
