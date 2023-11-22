#ifndef DOG_C
# define DOG_C
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog &dog);
		Dog& operator=(const Dog &dog);
		void makeSound() const;
		Brain *getBrain() const;
		~Dog();
};
#endif