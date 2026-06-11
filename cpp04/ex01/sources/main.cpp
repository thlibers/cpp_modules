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

	const int n = 4;
	Animal* animals[n];
	for (int i = 0; i < n; i++)
	{
		if (i < n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << animals[i]->getType() << " " << std::endl;
		animals[i]->makeSound();
	}
	for (int i = 0; i < n; i++)
		delete animals[i];

	return 0;
}
