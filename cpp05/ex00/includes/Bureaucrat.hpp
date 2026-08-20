# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat(std::string Name, int Grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &Cpy);
	Bureaucrat &operator=(const Bureaucrat &Cpy);
	std::string getName() const;
	int getGrade() const;
	void Increment();
	void Decrement();

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif