#include <string>
#include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name) {
	Zombie *newZombie;

	newZombie = new Zombie(name);
	return newZombie;
}