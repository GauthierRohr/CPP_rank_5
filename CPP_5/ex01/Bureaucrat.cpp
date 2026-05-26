#include "Bureaucrat.hpp"
#include "Form.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (maximum is 1)");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (minimum is 150)");
}

// Constr
Bureaucrat::Bureaucrat() :
	_name("default"),
	_grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Constructeur param : exception if invalid grade
Bureaucrat::Bureaucrat(std::string const & name, int grade) :
	_name(name),
	_grade(grade)
{
	std::cout << "Bureaucrat param constructor called for " << _name << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

// Copy constr
Bureaucrat::Bureaucrat(Bureaucrat const & other) :
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Affec
Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & other)
{
	std::cout << "Bureaucrat copy operator called" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

// Destr
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " << _name << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

// + grade
void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

// - grade
void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

// Sign form
void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because his grade (" << _grade << ") is lower than Form grade ("
				  << form.getGradeToSign() << ")" << std::endl;
	}
}

// Bureaucrat : <name>, bureaucrat grade <grade>.
std::ostream &	operator<<(std::ostream & os, Bureaucrat const & bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
