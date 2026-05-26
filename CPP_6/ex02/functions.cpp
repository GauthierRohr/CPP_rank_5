#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int random_choice = std::rand() % 3;
	if (random_choice == 0)
		return (new A());
	if (random_choice == 1)
		return (new B());
	return (new C());
}

void	identify(Base* pointer)
{
	if (dynamic_cast<A*>(pointer) != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(pointer) != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(pointer) != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "inconnu" << std::endl;
}

// Reference overload: dynamic_cast on reference throws std::bad_cast on failure
void	identify(Base& reference)
{
	try
	{
		(void)dynamic_cast<A&>(reference);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(reference);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(reference);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception&) {}

	std::cout << "inconnu" << std::endl;
}
