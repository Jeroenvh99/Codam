#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	_type = wrongAnimal.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	_type = wrongAnimal.getType();
	return *this;
}

const std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << _type << " says WrongAnimal sound" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal default destructor called" << std::endl;
}
