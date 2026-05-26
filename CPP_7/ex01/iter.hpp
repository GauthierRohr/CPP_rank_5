#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

// Apply func to each element; T can be const or non-const
template <typename T, typename F>
void	iter(T * array, size_t const len, F func)
{
	for (size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif
