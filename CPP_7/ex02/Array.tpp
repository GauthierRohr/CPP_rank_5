#ifndef ARRAY_TPP
# define ARRAY_TPP

// Constructeur par défaut : tableau vide
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

// Constructeur avec n : n éléments initialisés par défaut
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n)
{
}

// Constructeur par copie : copie profonde
template <typename T>
Array<T>::Array(Array const & other) : _data(new T[other._size]()), _size(other._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

// Opérateur d'affectation : copie profonde, libère l'ancienne mémoire
template <typename T>
Array<T> &	Array<T>::operator=(Array const & other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return (*this);
}

// Destructeur : libère le tableau
template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

// Accès par index, throw si hors limites
template <typename T>
T &	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Array: index out of bounds");
	return (_data[index]);
}

// Accès const par index, throw si hors limites
template <typename T>
T const &	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Array: index out of bounds");
	return (_data[index]);
}

// Retourne le nombre d'éléments
template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

#endif
