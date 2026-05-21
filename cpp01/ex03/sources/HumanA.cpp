#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	// std::cout << "HumanA Constructor called" << std::endl;
}

HumanA::~HumanA()
{
	// std::cout << "HumanA Destructor called" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
