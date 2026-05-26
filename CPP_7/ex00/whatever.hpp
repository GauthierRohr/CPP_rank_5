#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// Swap two values
template <typename T>
void	swap(T & a, T & b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

// Min of two values (returns b if equal)
template <typename T>
T const &	min(T const & a, T const & b)
{
	return (a < b ? a : b);
}

// Max of two values (returns b if equal)
template <typename T>
T const &	max(T const & a, T const & b)
{
	return (a > b ? a : b);
}

#endif
