#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(std::string Name, int SignGrade, int ExecGrade) : _name(Name), _signed(false), _signGrade(SignGrade), _execGrade(ExecGrade)
{
	// std::cout << "Constructor Called" << std::endl;
	if (SignGrade < 1 || ExecGrade < 1)
		throw GradeTooHighException();
	else if (SignGrade > 150 || ExecGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	// std::cout << "Destructor Called" << std::endl;
}

AForm::AForm(const AForm &Cpy) : _name(Cpy._name), _signed(Cpy._signed), _signGrade(Cpy._signGrade), _execGrade(Cpy._execGrade)
{
	// std::cout << "Copy Constructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &Cpy)
{
	// std::cout << "Copy Assignement Constructor Called" << std::endl;
	if (this != &Cpy)
	{
		this->_signed = Cpy._signed;
	}
	return (*this);
}

// Functions

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	this->executeAction();
}

// Print

std::ostream &operator<<(std::ostream &out, const AForm &src)
{
	out << src.getName() << ", AForm grade to sign " << src.getSignGrade() << ", grade to execute " << src.getExecGrade() << ", signed: " << (src.getSigned() ? "true" : "false") << ".";
	return out;
}
