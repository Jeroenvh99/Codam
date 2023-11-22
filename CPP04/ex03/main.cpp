#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

AMateria *ground = NULL;

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("");
	if (tmp) {
		std::cout << tmp->getType() << std::endl;
		me->equip(tmp);
	}
	ICharacter* bob = new Character(*((Character *)me));
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	me->use(-8, *me);
	bob->unequip(3);
	me->use(3, *bob);
	bob->use(3, *me);
	delete bob;
	delete me;
	delete src;
	delete ground;
	return 0;
}