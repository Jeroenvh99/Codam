#include <string>
#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const Weapon &weapon) {
	_type = weapon._type;
}

Weapon& Weapon::operator=(const Weapon &weapon) {
	this->_type = weapon._type;
	return *this;
}

Weapon::Weapon(std::string type) : _type(type) {}

const std::string &Weapon::getType() {
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}

Weapon::~Weapon() {}
