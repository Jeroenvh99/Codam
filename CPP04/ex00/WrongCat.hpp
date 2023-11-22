#ifndef WRONGCAT_C
# define WRONGCAT_C
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &wrongCat);
		WrongCat& operator=(const WrongCat &wrongCat);
		void makeSound() const;
		~WrongCat();
};
#endif