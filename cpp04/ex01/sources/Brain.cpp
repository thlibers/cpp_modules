#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &Cpy)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = Cpy._ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &Cpy)
{
	if (this != &Cpy)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = Cpy._ideas[i];
	}
	std::cout << "Brain copy assignement constructor called" << std::endl;
	return (*this);
}
