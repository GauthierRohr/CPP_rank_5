#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int	main()
{
	std::cout << "=> Test sujet <=" << std::endl;
	try
	{
		Span	sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test : Span plein <=" << std::endl;
	try
	{
		Span	sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test : moins de 2 nombres <=" << std::endl;
	try
	{
		Span	sp(5);
		sp.addNumber(42);
		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test : addRange avec 10 000 nombres <=" << std::endl;
	try
	{
		Span			sp(10000);
		std::vector<int>	big;

		for (int i = 0; i < 10000; i++)
			big.push_back(std::rand() % 100000);
		sp.addRange(big.begin(), big.end());
		std::cout << "size        = " << big.size() << std::endl;
		std::cout << "shortestSpan = " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan  = " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test : addRange dépassement capacité <=" << std::endl;
	try
	{
		Span			sp(5);
		std::vector<int>	toomany;

		for (int i = 0; i < 10; i++)
			toomany.push_back(i);
		sp.addRange(toomany.begin(), toomany.end());
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	return (0);
}
