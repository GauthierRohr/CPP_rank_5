#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>
# include <iostream>
# include <vector>
# include <list>
# include <deque>

// Trouve 1ere occurrence
template <typename T>
typename T::iterator	easyfind(T & container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return (it);
}

#endif
