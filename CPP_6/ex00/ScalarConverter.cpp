#include "ScalarConverter.hpp"
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <sstream>

// ---------------------------------------------------------------
// Détection du type du littéral passé en argument
// ---------------------------------------------------------------

// Retourne true si le littéral est un pseudo-littéral flottant spécial
// (nan, nanf, +inf, -inf, +inff, -inff).
static bool	is_pseudo_literal(std::string const & literal)
{
	return (literal == "nan"   || literal == "nanf"  ||
	        literal == "+inf"  || literal == "-inf"  ||
	        literal == "+inff" || literal == "-inff");
}

// Retourne true si le littéral représente un char (ex: 'a', 'Z').
static bool	is_char_literal(std::string const & literal)
{
	return (literal.length() == 3 &&
	        literal[0] == '\'' && literal[2] == '\'');
}

// Retourne true si le littéral représente un float (se termine par 'f'
// et contient un point ou est un pseudo-littéral).
static bool	is_float_literal(std::string const & literal)
{
	if (literal.empty())
		return (false);
	if (literal[literal.length() - 1] != 'f')
		return (false);
	std::string without_f = literal.substr(0, literal.length() - 1);
	if (without_f == "nan" || without_f == "+inf" || without_f == "-inf")
		return (true);
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

// Retourne true si le littéral représente un double (contient un point,
// pas de 'f' final, et est composé de chiffres/signe/point uniquement).
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

// Retourne true si le littéral représente un int (uniquement des chiffres,
// avec éventuellement un signe + ou - en tête).
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

// ---------------------------------------------------------------
// Affichage de chaque type scalaire
// ---------------------------------------------------------------

// Affiche la valeur convertie en char depuis une valeur double.
// Affiche "impossible" si hors plage, "Non displayable" si non imprimable.
static void	print_char(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) ||
	    value < 0.0 || value > 127.0)
	{
		std::cout << "impossible" << std::endl;
		// impossible : valeur hors plage du type char
		return ;
	}
	char char_value = static_cast<char>(value);
	if (!std::isprint(char_value))
	{
		std::cout << "Non displayable" << std::endl;
		// Non displayable : char valide mais non imprimable
		return ;
	}
	std::cout << "'" << char_value << "'" << std::endl;
	// affichage du char entre guillemets simples
}

// Affiche la valeur convertie en int depuis une valeur double.
// Affiche "impossible" si hors plage ou NaN/Inf.
static void	print_int(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) ||
	    value < static_cast<double>(std::numeric_limits<int>::min()) ||
	    value > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "impossible" << std::endl;
		// impossible : valeur hors plage du type int ou NaN/Inf
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
	// affichage de la valeur int
}

// Retourne une chaîne représentant un float avec au moins 1 décimale.
// Exemple : 42.0f, 42.42f, nanf, +inff, -inff.
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

// Retourne une chaîne représentant un double avec au moins 1 décimale.
// Exemple : 42.0, 42.42, nan, +inf, -inf.
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

// Affiche la valeur en float et en double depuis une valeur double.
static void	print_float_and_double(double value)
{
	float float_value = static_cast<float>(value);
	std::cout << "float: "  << float_to_string(float_value)  << std::endl;
	// affichage de la valeur float avec suffixe 'f'
	std::cout << "double: " << double_to_string(value) << std::endl;
	// affichage de la valeur double
}

// ---------------------------------------------------------------
// Conversion selon le type détecté
// ---------------------------------------------------------------

// Convertit un pseudo-littéral spécial (nan, +inf, etc.)
// et affiche les 4 types scalaires correspondants.
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

// Convertit un littéral de type char (ex: 'a')
// et affiche les 4 types scalaires correspondants.
static void	convert_char(std::string const & literal)
{
	char char_value = literal[1];
	double double_value = static_cast<double>(char_value);
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Convertit un littéral de type int
// et affiche les 4 types scalaires correspondants.
static void	convert_int(std::string const & literal)
{
	double double_value = static_cast<double>(std::atoi(literal.c_str()));
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Convertit un littéral de type float (ex: 4.2f)
// et affiche les 4 types scalaires correspondants.
static void	convert_float(std::string const & literal)
{
	double double_value = static_cast<double>(std::atof(literal.c_str()));
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// Convertit un littéral de type double (ex: 4.2)
// et affiche les 4 types scalaires correspondants.
static void	convert_double(std::string const & literal)
{
	double double_value = std::atof(literal.c_str());
	print_char(double_value);
	print_int(double_value);
	print_float_and_double(double_value);
}

// ---------------------------------------------------------------
// Méthode publique statique
// ---------------------------------------------------------------

// Détecte le type du littéral passé en argument et appelle
// la fonction de conversion correspondante.
// Affiche "Erreur : littéral inconnu" si aucun type ne correspond.
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
	// aucun type C++ ne correspond au littéral fourni
}
