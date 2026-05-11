#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "=> Test 1: ShrubberyCreationForm <=" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 136);
		ShrubberyCreationForm shrubForm("home");

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
		Bureaucrat robotomist("Robotomist", 45);
		RobotomyRequestForm robotForm("Bender");

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
		PresidentialPardonForm pardonForm("Arthur Dent");

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

		signer.signForm(pardonForm);
		lowGrade.executeForm(pardonForm);
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception catch : " << e.what() << std::endl;
	}

	return (0);
}
