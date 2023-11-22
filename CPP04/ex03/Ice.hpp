#ifndef ICE_C
# define ICE_C
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &Ice);
		Ice &operator=(const Ice &Ice);
		AMateria* clone() const;
		void use(ICharacter& target);
		~Ice();
};
#endif