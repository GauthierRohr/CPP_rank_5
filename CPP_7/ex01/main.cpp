#include <iostream>
#include <string>
#include "iter.hpp"

// Affiche un élément (version const)
template <typename T>
void	printElement(T const & element)
{
	std::cout << element << std::endl;
}

// Multiplie un entier par 2
void	doubleInt(int & n)
{
	n *= 2;
}

// Affiche la longueur d'une string
void	printLength(std::string const & s)
{
	std::cout << s << " (len=" << s.length() << ")" << std::endl;
}

int	main()
{
	std::cout << "=> Test 1 : tableau d'int (affichage) <=" << std::endl;
	int	ints[] = {1, 2, 3, 4, 5};
	::iter(ints, 5, printElement<int>);

	std::cout << std::endl;
	std::cout << "=> Test 2 : tableau d'int (modification) <=" << std::endl;
	::iter(ints, 5, doubleInt);
	::iter(ints, 5, printElement<int>);

	std::cout << std::endl;
	std::cout << "=> Test 3 : tableau de strings (const) <=" << std::endl;
	std::string	words[] = {"bonjour", "monde", "template"};
	::iter(words, 3, printLength);

	std::cout << std::endl;
	std::cout << "=> Test 4 : tableau const d'int <=" << std::endl;
	int const	constInts[] = {10, 20, 30};
	::iter(constInts, 3, printElement<int>);

	return (0);
}
