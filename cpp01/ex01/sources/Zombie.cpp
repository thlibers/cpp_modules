#include "../includes/Zombie.hpp"

// Zombie::Zombie(std::string name)
// {
// 	this->_name = name;
// 	std::cout << this->_name << " lived" << std::endl;
// }

// Zombie::~Zombie()
// {
// 	std::cout << this->_name << " died" << std::endl;
// }

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
