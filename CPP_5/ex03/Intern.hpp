#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern
{
public:
	Intern();
	Intern(Intern const & other);
	Intern &	operator=(Intern const & other);
	~Intern();

	// Create form by name
	AForm*	makeForm(std::string const & formName, std::string const & target) const;

private:
	// Factory functions
	static AForm*	createShrubbery(std::string const & target);
	static AForm*	createRobotomy(std::string const & target);
	static AForm*	createPresidential(std::string const & target);
};

#endif
