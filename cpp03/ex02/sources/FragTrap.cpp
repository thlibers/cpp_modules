#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name), state(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy), state(cpy.state)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &cpy)
{
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		this->state = cpy.state;
	}
	std::cout << "FragTrap " << this->_name << " assignment operator called" << std::endl;
	return (*this);
}

//	Functions :

void FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void FragTrap::highFivesGuys()
{
	if (this->state == false)
	{
		this->state = true;
		std::cout << "ScavTrap " << this->_name << " high-fives request!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " high-fives is already done!" << std::endl;
}
