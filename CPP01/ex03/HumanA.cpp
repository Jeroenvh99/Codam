#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA() {}

HumanA::HumanA(std::string name, Weapon weapon) {
	_name = name;
	_weapon = weapon;
}

HumanA::HumanA(const HumanA &humanA) {}

HumanA& HumanA::operator=(const HumanA &humanA) {
	return *this;
}

HumanA::~HumanA() {
	std::cout << "HumanA with name " << this->_name << " is about to be destroyed" << std::endl;
}
