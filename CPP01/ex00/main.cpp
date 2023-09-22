#include "Zombie.hpp"
#include <string>

Zombie *newZombie(std::string name);

int main() {
	Zombie creature = Zombie("mario");
	creature.announce();
	Zombie *othercreature = newZombie("me");
	othercreature->announce();
	delete othercreature;
	return 0;
}