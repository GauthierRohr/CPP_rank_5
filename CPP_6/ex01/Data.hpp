#ifndef DATA_HPP
# define DATA_HPP

# include <string>

// Structure de données utilisée pour tester la sérialisation.
// Contient plusieurs membres pour prouver que la structure n'est pas vide.
struct Data
{
	int			identifier;
	std::string	label;
	double		value;
};

#endif
