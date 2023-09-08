#include<iostream>
#include<string>
#include"Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie(){
	std::cout << this->_name << " is about to be destroyed, bye\n";
}

void Zombie::announce(){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}