#include "Character.hpp"

extern AMateria *ground;

Character::Character() : _name("nameless") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &character) : _name(character.getName()) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = character.getItem(i);
}

Character &Character::operator=(const Character &character) {
	if (this != &character) {
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
		}
	}
	_name = character.getName();
	for (int i = 0; i < 4; i++)
		_inventory[i] = character.getItem(i);
	return *this;
}

std::string const &Character::getName() const {
	return _name;
}

AMateria *Character::getItem(int idx) const {
	if (idx < 0 || idx > 3)
		return NULL;
	return _inventory[idx]->clone();
}

void Character::equip(AMateria* m) {
	int i;
	for (i = 0; i < 4; i++) {
		if (_inventory[i] == NULL)
			break;
	}
	if (i < 4)
		_inventory[i] = m;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return;
	if (ground != NULL)
		delete ground;
	ground = _inventory[idx];
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
	}
}
