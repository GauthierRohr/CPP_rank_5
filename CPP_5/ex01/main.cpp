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
		Bureaucrat noob("Noob", 100);
		Form presidentForm("PresidentForm", 5, 1);
		std::cout << noob << std::endl;
		std::cout << presidentForm << std::endl;
		noob.signForm(presidentForm);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 3: invalid grade form <=" << std::endl;
	try
	{
		Form invalidForm("Invalid : grade 0", 0, 50);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}
	try
	{
		Form invalidFormTwo("Invalid : grade 151", 151, 50);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}
	try
	{
		Form invalidFormTwo("Invalid : grade -12", -12, 50);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	return (0);
}
