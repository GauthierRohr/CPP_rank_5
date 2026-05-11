#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const & other);
	PresidentialPardonForm &	operator=(PresidentialPardonForm const & other);
	~PresidentialPardonForm();

	// Pardon target by Zaphod Beeblebrox
	virtual void	execute(Bureaucrat const & executor) const;

private:
	std::string	_target;
};

#endif
