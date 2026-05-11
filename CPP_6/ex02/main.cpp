#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"

// Exécute un cycle complet : génère un objet aléatoire, identifie via pointeur
// puis via référence, et libère la mémoire.
static void	run_one_test(int test_number)
{
	std::cout << "=> Test " << test_number << " <=" << std::endl;

	Base* generated_object = generate();

	std::cout << "identify(pointeur) : ";
	identify(generated_object);
	// identification via dynamic_cast sur pointeur

	std::cout << "identify(référence) : ";
	identify(*generated_object);
	// identification via dynamic_cast sur référence

	delete generated_object;
	// libération de la mémoire allouée par generate()
}

// Point d'entrée du programme.
// Initialise le générateur aléatoire et exécute plusieurs tests.
int	main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	// initialisation du générateur avec le temps courant

	int total_tests = 10;
	for (int index = 1; index <= total_tests; index++)
		run_one_test(index);

	return (0);
	// fin normale du programme
}
