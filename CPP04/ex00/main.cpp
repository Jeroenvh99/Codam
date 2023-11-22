#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	return 0;
}