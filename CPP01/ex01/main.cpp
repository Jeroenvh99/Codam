#include <string>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(){
	Zombie creature = Zombie("mario");
	creature.announce();
	Zombie *ZombieHorde = zombieHorde(8, "him");
	for (int i = 0; i < 8; i++) {
		ZombieHorde[i].announce();
	}
	delete[] ZombieHorde;
	return 0;
}