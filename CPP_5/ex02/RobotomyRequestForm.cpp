#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Constr
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45),
	_target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Constructeur param : sign=72, exec=45
RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << "RobotomyRequestForm param constructor called" << std::endl;
}

// Copy constr
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other) :
	AForm(other),
	_target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Affectation
RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	std::cout << "RobotomyRequestForm copy operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// Destr
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Drill noise, then 50% robotomize
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);

	std::cout << "Drrrrrr... BZZZZZ... *drilling noises*" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}
