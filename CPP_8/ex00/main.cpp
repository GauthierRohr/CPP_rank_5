#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int	main()
{
	std::cout << "💥 vector<int> trouvé 💥" << std::endl;
	std::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(42);
	vec.push_back(7);
	vec.push_back(99);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "💥 vector<int> pas trouvé 💥" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 100);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "💥 list<int> trouvé 💥" << std::endl;
	std::list<int>	lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	try
	{
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "💥 deque<int> non trouvé 💥" << std::endl;
	std::deque<int>	dq;
	dq.push_back(5);
	dq.push_back(15);
	try
	{
		std::deque<int>::iterator it = easyfind(dq, 99);
		std::cout << "Trouvé : " << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	return (0);
}
