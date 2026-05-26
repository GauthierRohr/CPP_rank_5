#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	AForm();
	AForm(std::string const & name, int gradeToSign, int gradeToExecute);
	AForm(AForm const & other);
	AForm &	operator=(AForm const & other);
	virtual ~AForm();

	// Get
	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void	beSigned(Bureaucrat const & bureaucrat);

	// Execute (pure virtual)
	virtual void	execute(Bureaucrat const & executor) const = 0;

protected:
	// Check exec requirements
	void	checkExecutionRequirements(Bureaucrat const & executor) const;

private:
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExecute;
};

std::ostream &	operator<<(std::ostream & os, AForm const & form);

#endif
