#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	printElement(T const & element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	increment(T & n)
{
	n++;
}

void	printLength(std::string const & s)
{
	if (s.length() <= 7)
		std::cout << s << "\t\t(len=" << s.length() << ")" << std::endl;
	else
		std::cout << s << "\t(len=" << s.length() << ")" << std::endl;
}

int	main()
{
	std::cout << "💥 Tableau int 💥" << std::endl;
	int	intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, printElement<int>);

	std::cout << std::endl;
	std::cout << "💥 Tableau int (modif) 💥" << std::endl;
	iter(intArray, 5, increment<int>);
	iter(intArray, 5, printElement<int>);

	std::cout << std::endl;
	std::cout << "💥 Tableau strings 💥" << std::endl;
	std::string	words[] = {"C'est", "l'histoire", "d'un", "pingouin", "qui", "respire",
		"par", "les", "fesses", "un", "jour", "il", "s'assoit", "et", "il", "meurt"};
	iter(words, 16, printLength);

	std::cout << std::endl;
	std::cout << "💥 Tableau const int 💥" << std::endl;
	int const	constIntArray[] = {10, 20, 30};
	iter(constIntArray, 3, printElement<int>);

	std::cout << std::endl;
	std::cout << "💥 Tableau char (increment) 💥" << std::endl;
	char	charArray[] = {'H', 'e', 'l', 'l', 'o'};
	iter(charArray, 5, increment<char>);
	iter(charArray, 5, printElement<char>);

	return (0);
}
