#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	_name = clap.getName();
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
	std::cout << "ClapTrap name constructor called from FragTrap" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
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
	// target.takeDamage(_attackDamage);
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > _hitPoints)
	{
		std::cout << "ClapTrap " << _name << " has taken too much damage, you instantly die." << std::endl;
		_hitPoints = 0;
		return;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, it now has " << _hitPoints << " hitpoints" << std::endl;
	if (_hitPoints == 0)
		std::cout << "0 hitpoints, you are dead" << std::endl;
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

void ClapTrap::info() const {
	std::cout << "Claptrap " << _name << " has " << _energyPoints << " energypoints and " << _hitPoints << " hitpoints and causes " << _attackDamage << " points of damage." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap " << _name << " is about to be destroyed." << std::endl;
}
