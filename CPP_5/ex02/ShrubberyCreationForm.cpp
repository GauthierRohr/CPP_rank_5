#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Constr
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137),
	_target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Constr param : sign=145, exec=137
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm param constructor called" << std::endl;
}

// Copy constr
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & other) :
	AForm(other),
	_target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Affectation
ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
	std::cout << "ShrubberyCreationForm copy operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

// Destr
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Write ASCII trees to <target>_shrubbery
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);

	std::string const	fileName = _target + "_shrubbery";
	std::ofstream		file;
	file.open(fileName.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << fileName << std::endl;
		return ;
	}
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file << std::endl;
	file << "       _-_        " << std::endl;
	file << "    /~~   ~~\\     " << std::endl;
	file << " /~~         ~~\\  " << std::endl;
	file << "{               } " << std::endl;
	file << " \\  _-     -_  /  " << std::endl;
	file << "   ~  \\ | /  ~    " << std::endl;
	file << "       | |        " << std::endl;
	file << "      _| |_       " << std::endl;
	file << "     /_____\\      " << std::endl;
	file.close();
	std::cout << "Shrubbery created in file: " << fileName << std::endl;
}
