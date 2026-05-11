#include <iostream>
#include <string>
#include "Array.hpp"

int	main()
{
	std::cout << "=> Test 1 : tableau vide <=" << std::endl;
	Array<int>	empty;
	std::cout << "size = " << empty.size() << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test 2 : tableau de 5 ints (init par défaut = 0) <=" << std::endl;
	Array<int>	ints(5);
	std::cout << "size = " << ints.size() << std::endl;
	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test 3 : modification et lecture <=" << std::endl;
	for (unsigned int i = 0; i < ints.size(); i++)
		ints[i] = (int)(i * 10);
	for (unsigned int i = 0; i < ints.size(); i++)
		std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test 4 : copie profonde <=" << std::endl;
	Array<int>	copy(ints);
	copy[0] = 999;
	std::cout << "ints[0] apres modif copie = " << ints[0] << " (doit etre 0)" << std::endl;
	std::cout << "copy[0] = " << copy[0] << " (doit etre 999)" << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test 5 : opérateur= <=" << std::endl;
	Array<int>	assigned;
	assigned = ints;
	assigned[1] = 777;
	std::cout << "ints[1] apres modif assigned = " << ints[1] << " (doit etre 10)" << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << " (doit etre 777)" << std::endl;

	std::cout << std::endl;
	std::cout << "=> Test 6 : out of bounds <=" << std::endl;
	try
	{
		std::cout << ints[10] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 7 : tableau de strings <=" << std::endl;
	Array<std::string>	words(3);
	words[0] = "bonjour";
	words[1] = "monde";
	words[2] = "template";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << "words[" << i << "] = " << words[i] << std::endl;

	return (0);
}
