#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

int main() {
	Animal* tux = new Dog();
	((Dog *)tux)->getBrain()->setIdea("Hi, this is my brain", 0);
	((Dog *)tux)->getBrain()->setIdea("This is another idea", 1);
	((Dog *)tux)->getBrain()->setIdea("you know, coming up with all these", 2);
	((Dog *)tux)->getBrain()->setIdea("is kinda tiring", 3);
	for (int i = 4; i < 100; i++) {
		((Dog *)tux)->getBrain()->setIdea("I\'m done", i);
	}
	Animal* anotherOne = new Dog(*((Dog *)tux));
	((Dog *)anotherOne)->getBrain()->setIdea("This is my different idea", 1);
	((Dog *)anotherOne)->getBrain()->setIdea("it\'s a bit crazy", 2);
	std::cout << "Tux\'s ideas" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << ((Dog *)tux)->getBrain()->getIdea(i) << std::endl;
	}
	std::cout << "AnotherOne\'s ideas" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << ((Dog *)anotherOne)->getBrain()->getIdea(i) << std::endl;
	}
	delete tux;
	delete anotherOne;
	return 0;
}