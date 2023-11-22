#include <iostream>
#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : AAnimal(cat) {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &cat) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &cat)
		return *this;
	delete _brain;
	_brain = new Brain();
	_type = cat.getType();
	for (int i = 0; i < 100; i++) {
		_brain->setIdea(cat.getBrain()->getIdea(i), i);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain() const {
	return _brain;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat default destructor called" << std::endl;
}