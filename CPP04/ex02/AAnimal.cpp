#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aAnimal) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	(void)aAnimal;
}

AAnimal& AAnimal::operator=(const AAnimal &aAnimal) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	(void)aAnimal;
	return *this;
}

const std::string &AAnimal::getType() const {
	return _type;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal default destructor called" << std::endl;
}
