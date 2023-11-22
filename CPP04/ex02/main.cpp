#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

int main() {
	// const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// delete meta;
	delete i;
	delete j;
	return 0;
}