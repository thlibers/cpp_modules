#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &Cpy) : AForm(Cpy), _target(Cpy._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &Cpy)
{
	if (this != &Cpy)
	{
		AForm::operator=(Cpy);
		this->_target = Cpy._target;
	}
	return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	std::srand(std::time(0));
	std::cout << "Brrrrzzzz... Vrrrrrr..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomy failed." << std::endl;
}
