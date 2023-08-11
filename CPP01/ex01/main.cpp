#include "Zombie.hpp"

int main(){
	Zombie creature = Zombie("mario");
	creature.announce();
	Zombie *zombieHorde = creature.zombieHorde(8, "him");
	for (int i = 0; i < 8; i++) {
		zombieHorde[i].announce();
	}
	delete[] zombieHorde;
	return 0;
}