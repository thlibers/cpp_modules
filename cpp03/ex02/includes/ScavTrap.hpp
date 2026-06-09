#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
	bool state;
public:
	ScavTrap(std::string Name);
	~ScavTrap();
	ScavTrap(const ScavTrap &cpy);
	ScavTrap &operator=(const ScavTrap &cpy);
	void guardGate();
	void attack(const std::string& target);
};

#endif