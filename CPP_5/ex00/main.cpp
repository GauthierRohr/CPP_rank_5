#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "=> Test 1: Valid <=" << std::endl;
	try
	{
		Bureaucrat gauthier("Gauthier", 42);
		std::cout << gauthier << std::endl;

		gauthier.incrementGrade();
		std::cout << "After incr : " << gauthier << std::endl;

		gauthier.decrementGrade();
		gauthier.decrementGrade();
		std::cout << "After 2 decr : " << gauthier << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 2: Grade too high (0) <=" << std::endl;
	try
	{
		Bureaucrat toohigh("Too High", 0);
		// Not printedd normally
		std::cout << toohigh << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 3: Grade too low (151) <=" << std::endl;
	try
	{
		Bureaucrat toolow("Too Low", 151);
		std::cout << toolow << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 4: Inc more than 1 <=" << std::endl;
	try
	{
		Bureaucrat gigaBoss("Giga Boss", 1);
		std::cout << gigaBoss << std::endl;
		gigaBoss.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 5: Decr more than 150 <=" << std::endl;
	try
	{
		Bureaucrat noob("Noob", 150);
		std::cout << noob << std::endl;
		noob.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	return (0);
}
