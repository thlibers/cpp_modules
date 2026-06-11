#include "../includes/Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &cpy) : _type(cpy._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &cpy)
{
	if (this != &cpy)
	{
		this->_type = cpy._type;
	}
	std::cout << "Animal copy assignement constructor called" << std::endl;
	return (*this);
}

//	Functions :

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << this->_type << " makes sound" << std::endl;
}
