#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &Cpy);
	Animal &operator=(const Animal &Cpy);
	std::string getType() const;
	virtual void makeSound() const;
};

#endif