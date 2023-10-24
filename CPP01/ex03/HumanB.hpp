#ifndef HUMANB_C
# define HUMANB_C
# include <string>
# include "Weapon.hpp"

class HumanB {
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanB();
		// HumanB(const HumanB &humanB);
		HumanB(std::string name);
		HumanB& operator=(const HumanB &humanB);
		void setWeapon(Weapon &weapon);
		void attack();
		~HumanB();
};
#endif
