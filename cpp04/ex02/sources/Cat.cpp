#include "../includes/Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &Cpy) : AAnimal(Cpy)
{
	this->_brain = new Brain(*Cpy._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &Cpy)
{
	if (this != &Cpy)
	{
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*Cpy._brain);
		this->_type = Cpy._type;
	}
	std::cout << "Cat copy assignement constructor called" << std::endl;
	return (*this);
}

//	Functions :

void Cat::makeSound() const
{
	std::cout << this->getType() << " is meowing!" << std::endl;
}
