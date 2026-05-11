#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const & other);
	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & other);
	~ShrubberyCreationForm();

	// Write ASCII trees to file
	virtual void	execute(Bureaucrat const & executor) const;

private:
	std::string	_target;
};

#endif
