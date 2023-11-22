#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &cure) : AMateria(cure) {}

Cure &Cure::operator=(const Cure &cure) {
	_type = cure.getType();
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}

Cure::~Cure() {}