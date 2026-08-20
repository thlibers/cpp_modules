# ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
	std::string const _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
public:
	Form(std::string Name, int SignGrade, int ExecGrade);
	~Form();
	Form(const Form &Cpy);
	Form &operator=(const Form &Cpy);
	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("The grade is too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("The grade is too low");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif