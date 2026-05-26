#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

// Entry point: parses positive integer arguments, runs Ford-Johnson sort
// on both std::vector and std::deque, and prints results with timing.
int	main(int argument_count, char **argument_values)
{
	if (argument_count < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
		// 1: no input integers provided
	}

	PmergeMe	sorter;

	try
	{
		sorter.parseArguments(argument_count, argument_values);
		sorter.run();
	}
	catch (std::runtime_error const & error)
	{
		std::cerr << "Error" << std::endl;
		(void)error;
		return (1);
		// 1: invalid argument or sort error
	}

	return (0);
	// 0: sort completed successfully
}
