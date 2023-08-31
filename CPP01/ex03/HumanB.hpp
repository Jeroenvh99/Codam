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
		HumanB(const HumanA &humanA);
		HumanB(std::string name);
		HumanB& operator=(const HumanA &humanA);
		setWeapon(Weapon weapon);
		void attack();
		~HumanB();
};
#endif
