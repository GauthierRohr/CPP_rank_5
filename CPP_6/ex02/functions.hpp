#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include "Base.hpp"

// Instancie aléatoirement A, B ou C et retourne un pointeur Base*.
Base*	generate(void);

// Identifie le type réel de l'objet pointé et l'affiche ("A", "B" ou "C").
// Utilise dynamic_cast sur pointeur (NULL si cast échoué).
void	identify(Base* pointer);

// Identifie le type réel de l'objet référencé et l'affiche ("A", "B" ou "C").
// Utilise dynamic_cast sur référence (exception std::bad_cast si échoué).
// Interdit d'utiliser un pointeur dans cette surcharge.
void	identify(Base& reference);

#endif
