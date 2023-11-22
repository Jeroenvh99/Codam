#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag.getName(), 100, 100, 30) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &frag) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	_name = frag.getName();
	_energyPoints = frag.getEnergy();
	_hitPoints = frag.getHit();
	return *this;
}

void FragTrap::attack(const std::string &target) {
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
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "Positive high fives request on the standard output" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " is about to be destroyed." << std::endl;
}
