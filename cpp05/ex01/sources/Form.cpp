#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form(std::string Name, int SignGrade, int ExecGrade) : _name(Name), _signed(false), _signGrade(SignGrade), _execGrade(ExecGrade)
{
	// std::cout << "Constructor Called" << std::endl;
	if (SignGrade < 1 || ExecGrade < 1)
		throw GradeTooHighException();
	else if (SignGrade > 150 || ExecGrade > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	// std::cout << "Destructor Called" << std::endl;
}

Form::Form(const Form &Cpy) : _name(Cpy._name), _signed(Cpy._signed), _signGrade(Cpy._signGrade), _execGrade(Cpy._execGrade)
{
	// std::cout << "Copy Constructor Called" << std::endl;
}

Form &Form::operator=(const Form &Cpy)
{
	// std::cout << "Copy Assignement Constructor Called" << std::endl;
	if (this != &Cpy)
	{
		this->_signed = Cpy._signed;
	}
	return (*this);
}

// Functions

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_signed = true;
}

// Print

std::ostream &operator<<(std::ostream &out, const Form &src)
{
	out << src.getName() << ", form grade to sign " << src.getSignGrade() << ", grade to execute " << src.getExecGrade() << ", signed: " << (src.getSigned() ? "true" : "false") << ".";
	return out;
}
