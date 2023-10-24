#include "Zombie.hpp"
#include <string>

int main() {
	Zombie creature = Zombie("mario");
	creature.announce();
	Zombie *othercreature = Zombie::newZombie("me");
	othercreature->announce();
	Zombie::randomChump("Henk");
	delete othercreature;
	return 0;
}