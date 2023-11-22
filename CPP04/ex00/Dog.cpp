#include <iostream>
#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	_type = dog.getType();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &dog) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	_type = dog.getType();
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woofwoof" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called" << std::endl;
}