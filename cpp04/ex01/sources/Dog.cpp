#include "../includes/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &Cpy) : Animal(Cpy)
{
	if (this->_brain)
			delete this->_brain;
	this->_brain = new Brain(*Cpy._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &Cpy)
{
	if (this != &Cpy)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*Cpy._brain);
		this->_type = Cpy._type;
	}
	std::cout << "Dog copy assignement constructor called" << std::endl;
	return (*this);
}

//	Functions :

void Dog::makeSound() const
{
	std::cout << this->getType() << " is barking!" << std::endl;
}
