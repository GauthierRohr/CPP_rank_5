#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "=> Test 1: Successful signing <=" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 30);
		Form taxForm("TaxForm", 50, 25);
		std::cout << alice << std::endl;
		std::cout << taxForm << std::endl;
		alice.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 2: Grade too low to sign <=" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 100);
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
	std::cout << "=> Test 3: Form with invalid grade <=" << std::endl;
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
