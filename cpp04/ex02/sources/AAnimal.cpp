#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &Cpy) : _type(Cpy._type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &Cpy)
{
	if (this != &Cpy)
	{
		this->_type = Cpy._type;
	}
	std::cout << "AAnimal copy assignement constructor called" << std::endl;
	return (*this);
}

//	Functions :

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::makeSound() const
{
	std::cout << this->_type << " makes sound" << std::endl;
}
