#include "../includes/Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cpy)
{
	if (this != &cpy)
	{
		this->_type = cpy._type;
	}
	std::cout << "Cat copy assignement constructor called" << std::endl;
	return (*this);
}

//	Functions :

void Cat::makeSound() const
{
	std::cout << this->getType() << " is meowing!" << std::endl;
}
