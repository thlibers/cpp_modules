#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	std::string _ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &Cpy);
	Brain &operator=(const Brain &cpy);
};

#endif