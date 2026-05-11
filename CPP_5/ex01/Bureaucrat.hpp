#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
public:
	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	Bureaucrat();
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(Bureaucrat const & other);
	Bureaucrat &	operator=(Bureaucrat const & other);
	~Bureaucrat();

	// Get
	std::string	getName() const;
	int			getGrade() const;

	// Grade
	void	incrementGrade();
	void	decrementGrade();

	// Sign form
	void	signForm(Form & form);

private:
	std::string const	_name;
	int					_grade;
};

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & bureaucrat);

#endif
