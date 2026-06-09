#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string	_name;
	int _hitPoints;
	int	_energyPoints;
	int	_attackDamage;
public:
	ClapTrap(std::string Name);
	~ClapTrap();
	ClapTrap(const ClapTrap &cpy);
	ClapTrap &operator=(const ClapTrap &cpy);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif