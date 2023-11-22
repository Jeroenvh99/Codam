#ifndef CHARACTER_C
# define CHARACTER_C
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character &character);
		Character &operator=(const Character &character);
		std::string const &getName() const;
		AMateria *getItem(int idx) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
};
#endif