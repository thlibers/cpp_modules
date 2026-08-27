#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &Cpy) : AForm(Cpy), _target(Cpy._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &Cpy)
{
	if (this != &Cpy)
	{
		AForm::operator=(Cpy);
		this->_target = Cpy._target;
	}
	return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((this->_target + "_shrubbery").c_str());
	file << "       ccee88oo\n";
	file << "    C8O8O8Q8PoOb o8oo\n";
	file << "   dOB69QO8PdUOpugoO9bD\n";
	file << "  CgggbU8OU qOp qOdoUOdcb\n";
	file << "      6OuU  /p u gcoUodpP\n";
	file << "        \\//  /douUP\n";
	file << "          \\////\n";
	file << "           |||/\\\n";
	file << "           |||\\/\n";
	file << "           |||||\n";
	file << "      	   //||||\\    \n";
	file.close();
}
