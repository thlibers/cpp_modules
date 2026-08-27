# ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
	std::string const _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
protected:
	virtual void executeAction() const = 0;
public:
	AForm(std::string Name, int SignGrade, int ExecGrade);
	virtual ~AForm() = 0;
	AForm(const AForm &Cpy);
	AForm &operator=(const AForm &Cpy);
	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(const Bureaucrat &executor) const;
	
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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("The form is not signed");
		}
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif