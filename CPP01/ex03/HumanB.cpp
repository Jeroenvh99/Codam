#include <string>
#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

// HumanB::HumanB() {}

// HumanB::HumanB(const HumanB &humanB) {}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB& HumanB::operator=(const HumanB &humanB) {
	return *this;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() {
	if (this->_weapon->getType() != "") {
        std::cout << _name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << _name << " doesn't have a weapon to attack." << std::endl;
	}
}

HumanB::~HumanB() {
	std::cout << "HumanB with name " << this->_name << " is about to be destroyed" << std::endl;
}