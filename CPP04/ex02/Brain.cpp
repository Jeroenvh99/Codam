#include <iostream>
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = brain.getIdea(i);
	}
}

Brain& Brain::operator=(const Brain &brain) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = brain.getIdea(i);
	}
	return *this;
}

void Brain::setIdea(std::string idea, int index) {
	if (index < 0 || index > 99)
	{
		std::cout << "Index out of bounds" << std::endl;
		return;
	}
	_ideas[index] = idea;
}

const std::string &Brain::getIdea(int index) const {
	if (index < 0 || index > 99)
	{
		std::cout << "Index out of bounds" << std::endl;
		return *(new std::string()); // need to free, this is not so nice
	}
	return _ideas[index];
}

Brain::~Brain() {
	std::cout << "Brain default destructor called" << std::endl;
}
