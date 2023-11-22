#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
	_type = wrongCat.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongCat) {
	_type = wrongCat.getType();
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}