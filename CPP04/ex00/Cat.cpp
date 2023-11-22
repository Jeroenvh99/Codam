#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) {
	_type = cat.getType();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &cat) {
	_type = cat.getType();
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called" << std::endl;
}