#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Constr
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	_target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Constructeur param : sign=25, exec=5
PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << "PresidentialPardonForm param constructor called" << std::endl;
}

// Copy constr
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other) :
	AForm(other),
	_target(other._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Affect
PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
	std::cout << "PresidentialPardonForm copy operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// Destr
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Pardon by Zaphod Beeblebrox
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
