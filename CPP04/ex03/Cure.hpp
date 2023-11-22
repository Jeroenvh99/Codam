#ifndef CURE_C
# define CURE_C
# include <string>
# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &cure);
		Cure &operator=(const Cure &cure);
		AMateria* clone() const;
		void use(ICharacter& target);
		~Cure();
};
#endif