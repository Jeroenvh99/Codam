#ifndef FRAGTRAP_C
# define FRAGTRAP_C
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &frag);
		FragTrap& operator=(const FragTrap &frag);
		void attack(const std::string &target);
		void highFivesGuys();
		~FragTrap();
};
#endif