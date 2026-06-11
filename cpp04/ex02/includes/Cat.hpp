#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;
public:
	Cat();
	~Cat();
	Cat(const Cat &Cpy);
	Cat &operator=(const Cat &Cpy);
	void makeSound() const;
};

#endif