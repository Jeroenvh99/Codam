#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = materiaSource.getMateria(i);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
	if (this != &materiaSource) {
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			if (_inventory[i] == NULL)
				break;
		}
	}
	for (int i = 0; i < 4; i++)
		_inventory[i] = materiaSource.getMateria(i);
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	int i;
	for (i = 0; i < 4; i++) {
		if (_inventory[i] == NULL)
			break;
	}
	if (i < 4)
		_inventory[i] = m;
}

AMateria* MateriaSource::getMateria(int idx) const {
	if (idx < 0 || idx > 3)
		return NULL;
	return _inventory[idx]->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL)
			break;
		if (_inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return 0;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		if (_inventory[i] == NULL)
			break;
	}
}