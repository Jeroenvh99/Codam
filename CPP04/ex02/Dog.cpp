#include <iostream>
#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : AAnimal(dog) {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &dog) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &dog)
		return *this;
	delete _brain;
	_brain = new Brain();
	_type = dog.getType();
	for (int i = 0; i < 100; i++) {
		_brain->setIdea(dog.getBrain()->getIdea(i), i);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woofwoof" << std::endl;
}

Brain *Dog::getBrain() const {
	return _brain;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog default destructor called" << std::endl;
}