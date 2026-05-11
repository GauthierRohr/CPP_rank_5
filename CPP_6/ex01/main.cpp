#include <iostream>
#include "Serializer.hpp"

// Affiche les membres d'une structure Data pour visualiser son contenu.
static void	print_data(Data* data_pointer)
{
	std::cout << "  identifier : " << data_pointer->identifier << std::endl;
	std::cout << "  label      : " << data_pointer->label << std::endl;
	std::cout << "  value      : " << data_pointer->value << std::endl;
}

// Teste la sérialisation et la désérialisation d'un pointeur Data*.
// Vérifie que le pointeur original et le pointeur restauré sont identiques.
static void	test_serialization()
{
	std::cout << "=> Test : Sérialisation / Désérialisation <=" << std::endl;

	Data original_data;
	original_data.identifier = 42;
	original_data.label = "test_gauthier";
	original_data.value = 3.14;

	std::cout << "Données originales :" << std::endl;
	print_data(&original_data);

	uintptr_t serialized = Serializer::serialize(&original_data);
	std::cout << "Valeur sérialisée (uintptr_t) : " << serialized << std::endl;
	// serialized : représentation entière de l'adresse du pointeur

	Data* restored_pointer = Serializer::deserialize(serialized);
	std::cout << "Données restaurées :" << std::endl;
	print_data(restored_pointer);

	if (restored_pointer == &original_data)
		std::cout << "Succès : les pointeurs sont identiques." << std::endl;
	// les deux pointeurs pointent vers la même adresse mémoire
	else
		std::cout << "Échec : les pointeurs diffèrent." << std::endl;
}

// Point d'entrée du programme.
int	main()
{
	test_serialization();
	return (0);
	// fin normale du programme
}
