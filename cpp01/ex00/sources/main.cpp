#include "../includes/Zombie.hpp"

int main()
{
	Zombie *zombie1 = newZombie("hkeromne");
	Zombie *zombie2 = newZombie("sbonneau");
	zombie1->announce();
	zombie2->announce();

	randomChump("marcheva");
	randomChump("yderridj");

	delete zombie1;
	delete zombie2;
	return 0;
}
