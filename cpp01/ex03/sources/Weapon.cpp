#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	// std::cout << "Weapon Constructor called" << std::endl;
}

Weapon::~Weapon()
{
	// std::cout << "Weapon Destructor called" << std::endl;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string Weapon::getType() const
{
	return (this->_type);
}
