#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// Echange les valeurs de deux paramètres
template <typename T>
void	swap(T & a, T & b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

// Retourne la plus petite valeur (ou b si égales)
template <typename T>
T const &	min(T const & a, T const & b)
{
	return (a < b ? a : b);
}

// Retourne la plus grande valeur (ou b si égales)
template <typename T>
T const &	max(T const & a, T const & b)
{
	return (a > b ? a : b);
}

#endif
