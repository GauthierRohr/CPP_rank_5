#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int	main()
{
	std::srand(std::time(NULL));
	std::cout << "=> Test 1: ShrubberyCreationForm <=" << std::endl;
	try
	{
		Bureaucrat gardener("Pilou", 137);
		ShrubberyCreationForm shrubForm("ShrubForm Tester");

		std::cout << gardener << std::endl;
		std::cout << shrubForm << std::endl;

		gardener.signForm(shrubForm);
		gardener.executeForm(shrubForm);
		std::cout << shrubForm << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 2: RobotomyRequestForm <=" << std::endl;
	try
	{
		Bureaucrat robotomist("Charlie", 45);
		RobotomyRequestForm robotForm("RobotForm Tester");

		std::cout << robotomist << std::endl;
		std::cout << robotForm << std::endl;
		robotomist.signForm(robotForm);

		robotomist.executeForm(robotForm);
		robotomist.executeForm(robotForm);
		robotomist.executeForm(robotForm);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 3: PresidentialPardonForm <=" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardonForm("PardonForm Tester");

		std::cout << president << std::endl;
		std::cout << pardonForm << std::endl;

		president.signForm(pardonForm);
		president.executeForm(pardonForm);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 4: Execute without signing <=" << std::endl;
	try
	{
		Bureaucrat worker("Worker", 1);
		PresidentialPardonForm unsignedForm("Target");

		worker.executeForm(unsignedForm);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=> Test 5: Grade too low to execute <=" << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 100);
		Bureaucrat signer("Signer", 1);
		PresidentialPardonForm pardonForm("Target");

		std::cout << lowGrade << std::endl;
		std::cout << signer << std::endl;
		std::cout << pardonForm << std::endl;

		signer.signForm(pardonForm);
		lowGrade.executeForm(pardonForm);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	return (0);
}
