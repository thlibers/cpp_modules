#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name), state(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy), state(cpy.state)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy)
{
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		this->state = cpy.state;
	}
	std::cout << "ScavTrap " << this->_name << " assignment operator called" << std::endl;
	return (*this);
}

//	Functions :

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	if (this->state == false)
	{
		this->state = true;
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is already in Gate keeper mode!" << std::endl;
}
