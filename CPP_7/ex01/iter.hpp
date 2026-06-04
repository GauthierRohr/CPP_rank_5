#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
# include <iostream>
# include <string>

template <typename T, typename F>
void	iter(T *array, size_t const len, F func)
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

template <typename T, typename F>
void	iter(T const *array, size_t const len, F func)
{
	for (size_t i = 0; i < len; ++i)
		func(array[i]);
}

#endif