#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal 
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