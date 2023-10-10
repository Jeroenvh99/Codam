#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap &clap) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	_name = clap.getName();
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap) {
	_name = clap.getName();
	_energyPoints = clap.getEnergy();
	_hitPoints = clap.getHit();
	_attackDamage = 0;
	return *this;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

unsigned int ClapTrap::getEnergy() const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getHit() const {
	return this->_hitPoints;
}

void ClapTrap::attack(const std::string &target) {
	if (_hitPoints == 0) {
		std::cout << "0 hitpoints, you are dead" << std::endl;
		return;
	}
	if (_energyPoints == 0){
		std::cout << "Not enough energypoints, I can\'t attack" << std::endl;
		return;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, it has now " << _hitPoints << " hitpoints" << std::endl;
	if (_hitPoints == 0)
		std::cout << "0 hitpoints, you died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "0 hitpoints, you are dead" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "Not enough energypoints, I can\'t get repaired" << std::endl;
		return;
	}
	_hitPoints += amount;
	--_energyPoints;
	std::cout << "ClapTrap " << _name << " repaired itself with " << amount << " points, it now has " << _hitPoints << " hitpoints" << std::endl;
}

ClapTrap::~ClapTrap() {}
