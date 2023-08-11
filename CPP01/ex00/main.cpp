#include "Zombie.hpp"

int main(){
	Zombie creature = Zombie("mario");
	creature.announce();
	Zombie *othercreature = creature.newZombie("me");
	othercreature->announce();
	delete othercreature;
	return 0;
}