#include <iostream>
#include <cstdlib>
#include <ctime>
#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Instancie aléatoirement un objet de type A, B ou C.
// Retourne un pointeur de type Base* pointant vers l'objet créé.
Base*	generate(void)
{
	int random_choice = std::rand() % 3;
	if (random_choice == 0)
		return (new A());
	// retourne une instance de A
	if (random_choice == 1)
		return (new B());
	// retourne une instance de B
	return (new C());
	// retourne une instance de C
}

// Identifie le type réel de l'objet pointé via dynamic_cast sur pointeur.
// Affiche "A", "B" ou "C" selon le type réel. Affiche "inconnu" si aucun ne correspond.
void	identify(Base* pointer)
{
	if (dynamic_cast<A*>(pointer) != NULL)
	{
		std::cout << "A" << std::endl;
		// type identifié : A
		return ;
	}
	if (dynamic_cast<B*>(pointer) != NULL)
	{
		std::cout << "B" << std::endl;
		// type identifié : B
		return ;
	}
	if (dynamic_cast<C*>(pointer) != NULL)
	{
		std::cout << "C" << std::endl;
		// type identifié : C
		return ;
	}
	std::cout << "inconnu" << std::endl;
	// aucun des types A, B, C ne correspond
}

// Identifie le type réel de l'objet référencé via dynamic_cast sur référence.
// Utilise try/catch car dynamic_cast sur référence lance std::bad_cast si échoué.
// Interdit d'utiliser un pointeur dans cette fonction.
void	identify(Base& reference)
{
	try
	{
		(void)dynamic_cast<A&>(reference);
		std::cout << "A" << std::endl;
		// type identifié : A
		return ;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<B&>(reference);
		std::cout << "B" << std::endl;
		// type identifié : B
		return ;
	}
	catch (std::exception&) {}

	try
	{
		(void)dynamic_cast<C&>(reference);
		std::cout << "C" << std::endl;
		// type identifié : C
		return ;
	}
	catch (std::exception&) {}

	std::cout << "inconnu" << std::endl;
	// aucun des types A, B, C ne correspond
}
