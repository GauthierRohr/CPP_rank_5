#include <iostream>
#include "Serializer.hpp"

static void	print_data(Data* data_pointer)
{
	std::cout << "  identifier : " << data_pointer->identifier	<< std::endl;
	std::cout << "  label      : " << data_pointer->label		<< std::endl;
	std::cout << "  value      : " << data_pointer->value		<< std::endl;
}

// Verif si pointer survit à la serialization -> deserialization
// uintptr_t est un entier assez grand pour contenir une adresse mémoire
// serialize ne fait que dire "ecris l'adresse 0x7ffeabc12345 comme un entier"
static void	test_serialization()
{
	std::cout << "=> Test : Sérialisation | Désérialisation <=" << std::endl;

	// std::cout << "Test si non instantiable fonctionnel : erreur compil" << std::endl;
  	// Serializer s;           

	Data original_data;
	original_data.identifier = 42;
	original_data.label = "test_gauthier";
	original_data.value = 3.14;

	std::cout << "Original :" << std::endl;
	std::cout << "  adresse    : " << &original_data << std::endl;
	print_data(&original_data);

	uintptr_t serialized = Serializer::serialize(&original_data);
	std::cout << "Serialisee :" << std::endl;
	std::cout << "  decimal    : " << serialized << std::endl;
	std::cout << "  hexadecimal: " << (void*)serialized << std::endl;
	std::cout << "  data a cette adresse :" << std::endl;
	print_data(reinterpret_cast<Data*>(serialized));

	Data* restored_pointer = Serializer::deserialize(serialized);
	std::cout << "Donnees restaurees :" << std::endl;
	std::cout << "  adresse    : " << restored_pointer << std::endl;
	print_data(restored_pointer);

	if (restored_pointer == &original_data)
		std::cout << "Succes,les pointeurs sont identiques." << std::endl;
	else
		std::cout << "Echec, les pointeurs sont differents." << std::endl;
}

int	main()
{
	test_serialization();
	return (0);
}
