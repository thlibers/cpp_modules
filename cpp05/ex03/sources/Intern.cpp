#include "../includes/Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

// Functions

AForm *Intern::createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	typedef AForm *(*FormCreator)(const std::string &);
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	const FormCreator creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	int index = 0;

	while (index < 3)
	{
		if (formName == names[index])
		{
			std::cout << "Intern creates " << names[index] << std::endl;
			return (creators[index](target));
		}
		++index;
	}
	std::cout << "Intern error: form '" << formName << "' does not exist" << std::endl;
	return (NULL);
}
