#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string _type;
public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal &Cpy);
	AAnimal &operator=(const AAnimal &Cpy);
	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif