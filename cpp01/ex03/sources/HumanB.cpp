#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	// std::cout << "HumanA Constructor called" << std::endl;
}

HumanB::~HumanB()
{
	// std::cout << "HumanA Destructor called" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (!this->_weapon)
		std::cout << this->_name << " attacks with their hands" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
