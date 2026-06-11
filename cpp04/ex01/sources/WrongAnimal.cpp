#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &Cpy) : _type(Cpy._type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &Cpy)
{
    if (this != &Cpy)
        this->_type = Cpy._type;
    std::cout << "WrongAnimal copy assignement constructor called" << std::endl;
    return (*this);
}

//	Functions :

std::string WrongAnimal::getType() const
{
    return this->_type;
}

void WrongAnimal::makeSound() const
{
    std::cout << this->_type << " is trumpeting!" << std::endl;
}
