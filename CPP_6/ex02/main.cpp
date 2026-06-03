#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"

static void	run_one_test(int test_number)
{
	std::cout << "=> Test " << test_number << " <=" << std::endl;

	Base* generated_object = generate();

	std::cout << "identify(pointeur) : ";
	identify(generated_object);

	std::cout << "identify(reference) : ";
	identify(*generated_object);
	std::cout << std::endl;

	delete generated_object;
}

int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	int total_tests = 6;
	for (int index = 1; index <= total_tests; index++)
		run_one_test(index);

	return (0);
}
