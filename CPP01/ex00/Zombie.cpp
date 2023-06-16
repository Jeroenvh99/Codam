void Zombie::announce(){
	std::cout << this.name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie Zombie::newZombie(std::string name){
	Zombie *newZombie;

	newZombie = new(Zombie);
	this.name = name;
	return newZombie;
}

void Zombie::randomChump(std::string name){
	newZombie(name);
	announce();
}

void Zombie::~Zombie(){
	std::cout << this.name << "is about to be destroyed, bye\n";
	delete(this);
}