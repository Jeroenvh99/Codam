#ifndef DOG_C
# define DOG_C
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
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