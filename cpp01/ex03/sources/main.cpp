#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

// int main()
// {
// 	{
// 	Weapon club = Weapon("crude spiked club");
// 	HumanA bob("Bob", club);
// 	bob.attack();
// 	club.setType("some other type of club");
// 	bob.attack();
// 	}
// 	{
// 	Weapon club = Weapon("crude spiked club");
// 	HumanB jim("Jim");
// 	jim.setWeapon(club);
// 	jim.attack();
// 	club.setType("some other type of club");
// 	jim.attack();
// 	}
// }

int main()
{
	{
	Weapon bat = Weapon("baseball bat");
	HumanA jhauvill("jhauvill", bat);
	jhauvill.attack();
	bat.setType("knife");
	jhauvill.attack();
	}
	{
	Weapon knuckles = Weapon("Brass Knuckles");
	HumanB yderridj("yderridj");
	yderridj.setWeapon(knuckles);
	yderridj.attack();
	knuckles.setType("bottle shard");
	yderridj.attack();
	}
}
