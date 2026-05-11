#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int	main()
{
	std::srand(std::time(NULL));
	std::cout << "=> Test 1: Intern creates RobotomyRequestForm <=" << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	robotomyForm;

		robotomyForm = someRandomIntern.makeForm("robotomy request", "Grosthier");
		if (robotomyForm != NULL)
		{
			std::cout << *robotomyForm << std::endl;

			Bureaucrat boss("Boss", 45);
			boss.signForm(*robotomyForm);
			boss.executeForm(*robotomyForm);
			delete robotomyForm;
		}
	}

	std::cout << std::endl;
	std::cout << "=> Test 2: Intern creates ShrubberyCreationForm <=" << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	shrubForm;

		shrubForm = someRandomIntern.makeForm("shrubbery creation", "HOUSEEEE");
		if (shrubForm != NULL)
		{
			Bureaucrat gardener("Gardener", 136);
			gardener.signForm(*shrubForm);
			gardener.executeForm(*shrubForm);
			delete shrubForm;
		}
	}

	std::cout << std::endl;
	std::cout << "=> Test 3: Intern creates PresidentialPardonForm <=" << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	pardonForm;

		pardonForm = someRandomIntern.makeForm("presidential pardon", "Grosthier");
		if (pardonForm != NULL)
		{
			Bureaucrat president("President", 1);
			president.signForm(*pardonForm);
			president.executeForm(*pardonForm);
			delete pardonForm;
		}
	}

	std::cout << std::endl;
	std::cout << "=> Test 4: Unknown form <=" << std::endl;
	{
		Intern	someRandomIntern;
		AForm*	unknownForm;

		unknownForm = someRandomIntern.makeForm("coffee machine form", "Target");
		if (unknownForm == NULL)
			std::cout << "Form creation failed as expected." << std::endl;
	}

	return (0);
}
