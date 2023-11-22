#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap bob("Bobbie");
	ScavTrap hans("Hans"); // 50 energy, 100 hit, 20 damage
	bob.info();
	hans.info();
	bob.attack("Hans");
	hans.takeDamage(0);
	hans.info();
	hans.attack("Bobbie");
	bob.takeDamage(20); // bob died
	hans.beRepaired(5);
	hans.takeDamage(13);
	bob.beRepaired(4); // bob is dead
	return 0;
}