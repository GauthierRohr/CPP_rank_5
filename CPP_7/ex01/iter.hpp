#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

// Applique une fonction à chaque élément du tableau
// T peut être const ou non-const selon le contexte
template <typename T, typename F>
void	iter(T * array, size_t const len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif
