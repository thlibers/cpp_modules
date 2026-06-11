#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &cpy);
	Animal &operator=(const Animal &cpy);
	std::string getType() const;
	virtual void makeSound() const;
};

#endif