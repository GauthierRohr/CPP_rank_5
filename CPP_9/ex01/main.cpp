#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

// Entry point: reads the RPN expression from the command line argument
// and prints the evaluated result or an error message to stderr.
int	main(int argument_count, char **argument_values)
{
	if (argument_count != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
		// 1: wrong number of arguments
	}

	RPN	calculator;

	try
	{
		int	result = calculator.evaluate(argument_values[1]);
		std::cout << result << std::endl;
		// result: evaluated value of the RPN expression
	}
	catch (std::runtime_error const & error)
	{
		std::cerr << "Error" << std::endl;
		(void)error;
		return (1);
		// 1: invalid expression or evaluation error
	}

	return (0);
	// 0: evaluation completed successfully
}
