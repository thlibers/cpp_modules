#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(j);
	delete(i);

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();

	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	wmeta->makeSound();

	delete(wmeta);
	delete(w);
	return 0;
}
