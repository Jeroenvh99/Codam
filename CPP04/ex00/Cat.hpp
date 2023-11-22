#ifndef CAT_C
# define CAT_C
# include "Animal.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cat);
		Cat& operator=(const Cat &cat);
		void makeSound() const;
		~Cat();
};
#endif