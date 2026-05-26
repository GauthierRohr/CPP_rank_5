#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

// Non-instantiable utility class for scalar literal conversion
class ScalarConverter
{
public:
	// Convert literal and print char/int/float/double
	static void	convert(std::string const & literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter &	operator=(ScalarConverter const & other);
	~ScalarConverter();
};

#endif
