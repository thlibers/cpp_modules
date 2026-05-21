#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

class Zombie
{
private:
	std::string _name;
public:
	// Zombie(std::string name);
	// ~Zombie();
	void setName(std::string name);
	// std::string getName() const;
	void announce();
};

Zombie* zombieHorde(int N, std::string name);

#endif