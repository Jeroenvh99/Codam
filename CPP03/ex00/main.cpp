#include "ClapTrap.hpp"

int main() {
	ClapTrap bob("Bobbie");
	bob.attack("Hans");
	bob.takeDamage(2);
	bob.beRepaired(5);
	bob.takeDamage(13); //you died
	bob.beRepaired(4); //not enough hitpoints
	return 0;
}