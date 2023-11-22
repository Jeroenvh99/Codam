#ifndef CAT_C
# define CAT_C
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const Cat &cat);
		Cat& operator=(const Cat &cat);
		void makeSound() const;
		Brain *getBrain() const;
		~Cat();
};
#endif