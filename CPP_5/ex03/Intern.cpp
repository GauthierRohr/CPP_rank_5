#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constr
Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

// Copy constr
Intern::Intern(Intern const & other)
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

// Affectation
Intern &	Intern::operator=(Intern const & other)
{
	(void)other;
	std::cout << "Intern copy operator called" << std::endl;
	return (*this);
}

// Destr
Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm*	Intern::createShrubbery(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomy(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidential(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

// Map name -> factory, avoid if/else chain
struct FormEntry
{
	std::string	name;
	AForm*		(*create)(std::string const &);
};

// Creates form matching formName, NULL if unknown
AForm*	Intern::makeForm(std::string const & formName, std::string const & target) const
{
	FormEntry	entries[3];
	entries[0].name   = "shrubbery creation";
	entries[0].create = &createShrubbery;
	entries[1].name   = "robotomy request";
	entries[1].create = &createRobotomy;
	entries[2].name   = "presidential pardon";
	entries[2].create = &createPresidential;

	int const	numberOfForms = 3;
	int			index = 0;
	while (index < numberOfForms)
	{
		if (entries[index].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (entries[index].create(target));
		}
		index++;
	}
	std::cerr << "Error: form '" << formName << "' does not exist." << std::endl;
	return (NULL);
}
