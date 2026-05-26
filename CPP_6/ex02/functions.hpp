#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include "Base.hpp"

// Randomly allocate A, B or C; return Base*
Base*	generate(void);

// Identify real type via pointer dynamic_cast; print A/B/C
void	identify(Base* pointer);

// Identify real type via reference dynamic_cast (throws on fail; no pointer allowed)
void	identify(Base& reference);

#endif
