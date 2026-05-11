#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
public:
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

	Form();
	Form(std::string const & name, int gradeToSign, int gradeToExecute);
	Form(Form const & other);
	Form &	operator=(Form const & other);
	~Form();

	// Get
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	// Sign
	void	beSigned(Bureaucrat const & bureaucrat);

private:
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExecute;
};

std::ostream &	operator<<(std::ostream & os, Form const & form);

#endif
