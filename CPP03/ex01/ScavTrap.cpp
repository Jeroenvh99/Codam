#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = scav.getName();
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scav) {
	_name = scav.getName();
	return *this;
}

ScavTrap::attack() {
	if (_hitPoints == 0) {
		std::cout << "0 hitpoints, you are dead" << std::endl;
		return;
	}
	if (_energyPoints == 0){
		std::cout << "Not enough hitpoints or energypoints, I can\'t attack" << std::endl;
		return;
	}
	--_energyPoints;
	// target.takeDamage(_attackDamage);
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

ScavTrap::guardGate() {
	std::cout << "I\'m now in Gatekeeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called" << std::endl;
}