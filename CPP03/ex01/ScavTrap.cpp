#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {}

ScavTrap::ScavTrap(const ScavTrap &scav) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	_name = scav.getName();
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scav) {
	_name = scav.getName();
	return *this;
}

ScavTrap::guardGate() {
	std::cout << "I\'m now in Gatekeeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {}