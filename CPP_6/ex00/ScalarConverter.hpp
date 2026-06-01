#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <sstream>

// Non instantiable
class ScalarConverter
{
public:
	static void	convert(std::string const & literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter &	operator=(ScalarConverter const & other);
	~ScalarConverter();
};

#endif
