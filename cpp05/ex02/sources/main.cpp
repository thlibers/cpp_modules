#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat jhauvill("jhauvill", 150);
		Bureaucrat marcheva("marcheva", 40);
		Bureaucrat thlibers("thlibers", 1);

		ShrubberyCreationForm shrubbery("ytennah");
		RobotomyRequestForm robotomy("mlaval");
		PresidentialPardonForm pardon("aandreo");

		std::cout << jhauvill << std::endl;
		std::cout << marcheva << std::endl;
		std::cout << thlibers << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		jhauvill.signForm(shrubbery);
		marcheva.signForm(shrubbery);
		thlibers.signForm(robotomy);
		thlibers.signForm(pardon);

		jhauvill.executeForm(shrubbery);
		marcheva.executeForm(shrubbery);
		thlibers.executeForm(shrubbery);

		jhauvill.executeForm(robotomy);
		thlibers.executeForm(robotomy);

		marcheva.executeForm(pardon);
		thlibers.executeForm(pardon);

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
