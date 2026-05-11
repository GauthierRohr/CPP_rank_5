#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(Array const & other);
	Array &		operator=(Array const & other);
	~Array();

	// Accès par index (non-const et const)
	T &				operator[](unsigned int index);
	T const &		operator[](unsigned int index) const;

	// Nombre d'éléments
	unsigned int	size() const;

private:
	T *				_data;
	unsigned int	_size;
};

# include "Array.tpp"

#endif
