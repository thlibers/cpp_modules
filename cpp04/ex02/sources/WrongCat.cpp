#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &Cpy) : WrongAnimal(Cpy)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &Cpy)
{
    if (this != &Cpy)
        this->_type = Cpy._type;
    std::cout << "WrongCat copy assignement constructor called" << std::endl;
    return (*this);
}
