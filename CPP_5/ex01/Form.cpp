#include "Form.hpp"
#include "Bureaucrat.hpp"

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high (minimum is 1)");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low (maximum is 150)");
}

// Constr
Form::Form() :
	_name("default"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

// Constructeur param : exception if invalid grades
Form::Form(std::string const & name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << "Form param constructor called for " << _name << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy constr
Form::Form(Form const & other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

// Affec
Form &	Form::operator=(Form const & other)
{
	std::cout << "Form copy operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

// Destr
Form::~Form()
{
	std::cout << "Form destructor called for " << _name << std::endl;
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Sign if grade sufficient
void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Form : <name> | Signed | grades
std::ostream &	operator<<(std::ostream & os, Form const & form)
{
	os << "Form: " << form.getName()
	   << " | Signed: " << (form.getIsSigned() ? "yes" : "no")
	   << " | Grade to sign: " << form.getGradeToSign()
	   << " | Grade to execute: " << form.getGradeToExecute();
	return (os);
}
