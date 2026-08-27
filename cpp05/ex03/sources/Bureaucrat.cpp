#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(std::string Name, int Grade) : _name(Name)
{
	// std::cout << "Constructor Called" << std::endl;
	if (Grade < 1)
		throw GradeTooHighException();
	else if (Grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = Grade;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Cpy) : _name(Cpy._name), _grade(Cpy._grade)
{
	// std::cout << "Copy Constructor Called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &Cpy)
{
	// std::cout << "Copy Assignement Constructor Called" << std::endl;
	if (this != &Cpy)
		this->_grade = Cpy._grade;
	return (*this);
}

// Functions

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::Increment()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::Decrement()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

// Add

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Print

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", Bureaucrat grade " << src.getGrade() << ".";
	return out;
}
