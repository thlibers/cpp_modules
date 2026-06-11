#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal 
{
private:
	Brain *_brain;
public:
	Dog();
	~Dog();
	Dog(const Dog &Cpy);
	Dog &operator=(const Dog &Cpy);
	void makeSound() const;
};

#endif