# ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
protected:
	void executeAction() const;
public:
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &Cpy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &Cpy);
};

#endif