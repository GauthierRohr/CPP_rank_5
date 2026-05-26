#include "ScalarConverter.hpp"
#include <iostream>

// Expects exactly one arg (the literal to convert)
int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <littéral>" << std::endl;
		return (1);
	}

	std::cout << "=> Test : " << argv[1] << " <=" << std::endl;
	ScalarConverter::convert(std::string(argv[1]));

	std::cout << std::endl;

	std::cout << "=> Tests autres <=" << std::endl;

	std::cout << std::endl;
	std::cout << "-- char 'a' --" << std::endl;
	ScalarConverter::convert("'a'");

	std::cout << std::endl;
	std::cout << "-- int 0 --" << std::endl;
	ScalarConverter::convert("0");

	std::cout << std::endl;
	std::cout << "-- int -42 --" << std::endl;
	ScalarConverter::convert("-42");

	std::cout << std::endl;
	std::cout << "-- float 42.0f --" << std::endl;
	ScalarConverter::convert("42.0f");

	std::cout << std::endl;
	std::cout << "-- float -4.2f --" << std::endl;
	ScalarConverter::convert("-4.2f");

	std::cout << std::endl;
	std::cout << "-- double 42.0 --" << std::endl;
	ScalarConverter::convert("42.0");

	std::cout << std::endl;
	std::cout << "-- nan --" << std::endl;
	ScalarConverter::convert("nan");

	std::cout << std::endl;
	std::cout << "-- +inff --" << std::endl;
	ScalarConverter::convert("+inff");

	std::cout << std::endl;
	std::cout << "-- -inf --" << std::endl;
	ScalarConverter::convert("-inf");

	return (0);
}
