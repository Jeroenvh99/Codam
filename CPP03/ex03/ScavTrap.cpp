#include <iostream>
#include <string>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav.getName(), 100, 50, 20) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scav) {
	_name = scav.getName();
	return *this;
}

void ScavTrap::attack(const std::string &target) {
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

void ScavTrap::guardGate() {
	std::cout << "I\'m now in Gatekeeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " is about to be destroyed." << std::endl;
}