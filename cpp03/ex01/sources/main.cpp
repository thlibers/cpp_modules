#include "../includes/ScavTrap.hpp"

int main()
{
	ScavTrap	a("yderridj");
	ScavTrap	b("ytennah");

	a.attack("ytennah");
	b.takeDamage(3);
	b.beRepaired(2);

	b.attack("yderridj");
	a.takeDamage(5);
	a.beRepaired(4);

	a.guardGate();
	b.guardGate();

	return (0);
}