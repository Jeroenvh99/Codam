#include <iostream>
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamond) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "This diamondtrap is called " << _name << ", it's clapname is " << ClapTrap::_name << "." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " is about to be destroyed." << std::endl;
}
