#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>

// On charge la database CSV et le fichier input 
// Usage: ./btc <input_file>
int	main(int argument_count, char **argument_values)
{
	if (argument_count != 2)
	{
		std::cout << "Error: usage : ./btc <input_file>" << std::endl;
		return (1);
	}

	BitcoinExchange	exchange;

	try
	{
		exchange.loadDatabase("data.csv");
	}
	catch (std::runtime_error const & error)
	{
		std::cerr << "Error: " << error.what() << std::endl;
		return (1);
		// 1: database load failed
	}

	exchange.processInputFile(argument_values[1]);

	return (0);
	// 0: program completed successfully
}
