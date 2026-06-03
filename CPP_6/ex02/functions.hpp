#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

// Alloue A, B ou C
// retourne Base*
Base*	generate(void);

// Identifie type avec pointeuur dynamic_cast;
// print A, B ou C
void	identify(Base* pointer);

// Identifie type avec reference dynamic_cast
// throw si erreur
void	identify(Base& reference);

#endif
