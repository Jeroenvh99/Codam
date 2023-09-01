#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

// HumanA::HumanA() {}

// HumanA::HumanA(const HumanA &humanA) {}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA& HumanA::operator=(const HumanA &humanA) {
	return *this;
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "HumanA with name " << this->_name << " is about to be destroyed" << std::endl;
}