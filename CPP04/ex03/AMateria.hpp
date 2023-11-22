#ifndef AMATERIA_C
# define AMATERIA_C
# include <string>
# include "ICharacter.hpp"

class AMateria {
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &aMateria);
		AMateria &operator=(const AMateria &aMateria);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};
#endif