#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int main()
{
	FragTrap	a("yderridj");
	FragTrap	b("ytennah");
	ScavTrap	c("jhauvill");
	ScavTrap	d("aronnet");

	c.attack("aronnet");
	d.takeDamage(3);
	d.beRepaired(2);

	d.attack("jhauvill");
	c.takeDamage(5);
	c.beRepaired(4);

	c.guardGate();
	d.guardGate();

	a.attack("ytennah");
	b.takeDamage(3);
	b.beRepaired(2);

	b.attack("yderridj");
	a.takeDamage(5);
	a.beRepaired(4);

	a.highFivesGuys();
	b.highFivesGuys();

	return (0);
}