#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
{
	this->_name = Name;
	std::cout << "Constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << this->_attackDamage << "points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " repaires " << amount << "points of heal!" << std::endl;
}
