#ifndef HUMANB_C
# define HUMANB_C
# include <string>
# include "Weapon.hpp"

class HumanB{
	private:
		Weapon _weapon;
		std::string _name;
	public:
		HumanB();
		HumanB(std::string name);
		HumanB(const HumanA &humanA);
		HumanB& operator=(const HumanA &humanA);
		~HumanB();
		setWeapon(Weapon weapon);
		attack();
};
#endif
