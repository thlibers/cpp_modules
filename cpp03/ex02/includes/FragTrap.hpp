#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
protected:
	bool state;
public:
	FragTrap(std::string Name);
	~FragTrap();
	FragTrap(const FragTrap &cpy);
	FragTrap &operator=(const FragTrap &cpy);
	void highFivesGuys();
	void attack(const std::string& target);
};

#endif