#include <iostream>
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cout << "Animal copy constructor called" << std::endl;
	_type = animal.getType();
}

Animal& Animal::operator=(const Animal &animal) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	_type = animal.getType();
	return *this;
}

const std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called" << std::endl;
}
