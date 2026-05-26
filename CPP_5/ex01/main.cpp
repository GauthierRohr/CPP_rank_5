#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "=> Test 1: ok sign <=" << std::endl;
	try
	{
		Bureaucrat jeandenis("Jean-Denis Soukoudefouait", 30);
		Form interneSoumisEtEfficace("Contrat de travail Sous Soumission intense", 50, 25);
		std::cout << jeandenis << std::endl;
		std::cout << interneSoumisEtEfficace << std::endl;
		jeandenis.signForm(interneSoumisEtEfficace);
		std::cout << interneSoumisEtEfficace << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 2: too low to sign <=" << std::endl;
	try
	{
		Bureaucrat bob("noob", 100);
		Form presidentForm("PresidentForm", 5, 1);
		std::cout << bob << std::endl;
		std::cout << presidentForm << std::endl;
		bob.signForm(presidentForm);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 3: invalid grade form <=" << std::endl;
	try
	{
		Form invalidForm("Invalid", 0, 50);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	return (0);
}
