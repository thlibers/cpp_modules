#include "../includes/ClapTrap.hpp"

int main()
{
	ClapTrap	a("yderridj");
	ClapTrap	b("ytennah");

	a.attack("ytennah");
	b.takeDamage(3);
	b.beRepaired(2);

	b.attack("yderridj");
	a.takeDamage(5);
	a.beRepaired(4);

	return (0);
}