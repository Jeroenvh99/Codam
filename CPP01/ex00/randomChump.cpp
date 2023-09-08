#include"Zombie.hpp"

void Zombie::randomChump(std::string name){
	randomZombie = newZombie(name);
	randomZombie.announce();
}