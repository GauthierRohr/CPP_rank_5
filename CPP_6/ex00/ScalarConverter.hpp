#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

// Classe utilitaire de conversion de littéraux scalaires C++.
// Non instanciable : constructeur et opérateur d'affectation privés.
class ScalarConverter
{
public:
	// Convertit un littéral C++ et affiche sa valeur en char, int, float, double.
	static void	convert(std::string const & literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter &	operator=(ScalarConverter const & other);
	~ScalarConverter();
};

#endif
