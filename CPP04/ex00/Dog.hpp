#ifndef DOG_C
# define DOG_C
# include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &dog);
		Dog& operator=(const Dog &dog);
		void makeSound() const;
		~Dog();
};
#endif