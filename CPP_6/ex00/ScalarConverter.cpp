#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <sstream>

// TYPE DETECTION

// True if special pseudo-literal
static bool	is_pseudo_literal(std::string const & literal)
{
	return (literal == "nan"   || literal == "nanf"  ||
	        literal == "+inf"  || literal == "-inf"  ||
	        literal == "+inff" || literal == "-inff");
}

// True if char literal
static bool	is_char_literal(std::string const & literal)
{
	return (literal.length() == 3 &&
	        literal[0] == '\'' && literal[2] == '\'');
}

// True if float literal :
// - ends with 'f' & has dot
static bool	is_float_literal(std::string const & literal)
{
	if (literal.empty())
		return (false);
	if (literal[literal.length() - 1] != 'f')
		return (false);
	std::string without_f = literal.substr(0, literal.length() - 1);
	bool has_dot = false;
	size_t start = 0;
	if (without_f[0] == '+' || without_f[0] == '-')
		start = 1;
	for (size_t index = start; index < without_f.length(); index++)
	{
		if (without_f[index] == '.')
			has_dot = true;
		else if (!std::isdigit(without_f[index]))
			return (false);
	}
	return (has_dot);
}

// True if double literal :
//	- has dot & no 'f' & digits/sign only
static bool	is_double_literal(std::string const & literal)
{
	if (literal.empty())
		return (false);
	bool has_dot = false;
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	for (size_t index = start; index < literal.length(); index++)
	{
		if (literal[index] == '.')
			has_dot = true;
		else if (!std::isdigit(literal[index]))
			return (false);
	}
	return (has_dot);
}

// True if int literal : 
//	- digits only, + or - sign = OK
static bool	is_int_literal(std::string const & literal)
{
	if (literal.empty())
		return (false);
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	if (start == literal.length())
		return (false);
	for (size_t index = start; index < literal.length(); index++)
	{
		if (!std::isdigit(literal[index]))
			return (false);
	}
	return (true);
}

// Type printers

// Print as char
// "impossible" :		if out of range
// "Non displayable" :	if non-printable
static void	print_char(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0.0 || value > 127.0)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char char_value = static_cast<char>(value);
	if (!std::isprint(char_value))
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << char_value << "'" << std::endl;
}

// Print as int
// "impossible" : if out of range OR NaN/Inf
static void	print_int(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) ||
	    value < static_cast<double>(std::numeric_limits<int>::min()) ||
	    value > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

// Float to string with at least 1 decimal (42.0f, nanf, +inff)
// fixed     : decimal notation, not scientific (42.0 not 4.2e+01)
// precision : minimum 1 decimal digit (subj)
static std::string	float_to_string(float float_value)
{
	if (std::isnan(float_value))
		return ("nanf");
	if (std::isinf(float_value))
	{
		if (float_value > 0)
			return ("+inff");
		return ("-inff");
	}
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(1) << float_value;
	return (stream.str() + "f");
}

// Double to string with at least 1 decimal (e.g. 42.0, nan, +inf)
static std::string	double_to_string(double double_value)
{
	if (std::isnan(double_value))
		return ("nan");
	if (std::isinf(double_value))
	{
		if (double_value > 0)
			return ("+inf");
		return ("-inf");
	}
	std::ostringstream stream;
	stream << std::fixed << std::setprecision(1) << double_value;
	return (stream.str());
}

static void	print_float_and_double(double value)
{
	float float_value = static_cast<float>(value);
	std::cout << "float: "  << float_to_string(float_value)  << std::endl;
	std::cout << "double: " << double_to_string(value) << std::endl;
}

// CONVERTERS

// Convert special pseudo-literal and print all 4 types
// Il existe deux types de NaN en IEEE 754 :
//	- quiet (silencieux, ne déclenche pas de signal CPU)
//	- signaling (lève une exception flottante à la première utilisation)
// ->  quiet ici car on veut juste représenter une valeur invalide sans crash
static void	convert_pseudo(std::string const & literal)
{
	double double_value;
	if (literal == "nan" || literal == "nanf")
		double_value = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "+inf" || literal == "+inff")
		double_value = std::numeric_limits<double>::infinity();
	else
		double_value = -std::numeric_limits<double>::infinity();
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Convert char literal and print all 4 types
static void	convert_char(std::string const & literal)
{
	char char_value = literal[1];
	double double_value = static_cast<double>(char_value);
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Convert int literal and print all 4 types
static void	convert_int(std::string const & literal)
{
	double double_value = static_cast<double>(std::atoi(literal.c_str()));
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Convert float literal and print all 4 types
static void	convert_float(std::string const & literal)
{
	double double_value = static_cast<double>(std::atof(literal.c_str()));
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Convert double literal and print all 4 types
static void	convert_double(std::string const & literal)
{
	double double_value = std::atof(literal.c_str());
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Public static method

// Detect literal type and dispatch to the right converter
void	ScalarConverter::convert(std::string const & literal)
{
	if (is_pseudo_literal(literal))
	{
		convert_pseudo(literal);
		return ;
	}
	if (is_char_literal(literal))
	{
		convert_char(literal);
		return ;
	}
	if (is_int_literal(literal))
	{
		convert_int(literal);
		return ;
	}
	if (is_float_literal(literal))
	{
		convert_float(literal);
		return ;
	}
	if (is_double_literal(literal))
	{
		convert_double(literal);
		return ;
	}
	std::cerr << "Erreur : littéral '" << literal << "' non reconnu." << std::endl;
}
