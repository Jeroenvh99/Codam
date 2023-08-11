#ifndef HUMANA_C
# define HUMANA_C
# include <string>
# include "Weapon.hpp"

class HumanA{
	private:
		Weapon _weapon;
		std::string _name;
	public:
		HumanA();
		HumanA(std::string name, Weapon weapon);
		HumanA(const HumanA &humanA);
		HumanA& operator=(const HumanA &humanA);
		~HumanA();
		attack();
};
#endif
