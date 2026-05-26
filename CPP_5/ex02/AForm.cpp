#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high (maximum is 1)");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low (minimum is 150)");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

// Constr
AForm::AForm() :
	_name("default"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

// Constructeur param : exception if invalid grades
AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << "AForm param constructor called for " << _name << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy constr
AForm::AForm(AForm const & other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

// Affec
AForm &	AForm::operator=(AForm const & other)
{
	std::cout << "AForm copy operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

// Destr
AForm::~AForm()
{
	std::cout << "AForm destructor called for " << _name << std::endl;
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Sign if grade sufficient
void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Check signed + grade before execute
void	AForm::checkExecutionRequirements(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
}

// AForm : <name> | Signed | grades
std::ostream &	operator<<(std::ostream & os, AForm const & form)
{
	os << "Form: " << form.getName()
	   << " | Signed: " << (form.getIsSigned() ? "yes" : "no")
	   << " | Grade to sign: " << form.getGradeToSign()
	   << " | Grade to execute: " << form.getGradeToExecute();
	return (os);
}
