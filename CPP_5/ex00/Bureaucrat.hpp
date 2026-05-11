#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
	Bureaucrat & operator=(Bureaucrat const & other);
	~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

private:
	std::string const	_name;
	int					_grade;
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & bureaucrat);

#endif
