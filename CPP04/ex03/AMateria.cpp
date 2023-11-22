#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &aMateria) : _type(aMateria.getType()) {}

AMateria &AMateria::operator=(const AMateria &aMateria) {
	(void)aMateria;
	return *this;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "undefined behaviour" << std::endl;
}

AMateria::~AMateria() {}
