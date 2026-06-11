#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &cpy)
{
	if (this != &cpy)
	{
		this->_type = cpy._type;
	}
	std::cout << "Dog copy assignement constructor called" << std::endl;
	return (*this);
}

//	Functions :

void Dog::makeSound() const
{
	std::cout << this->getType() << " is barking!" << std::endl;
}
