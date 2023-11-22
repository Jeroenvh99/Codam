#ifndef SCAVTRAP_C
# define SCAVTRAP_C
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scav);
		ScavTrap& operator=(const ScavTrap &scav);
		void attack(const std::string &target);
		void guardGate();
		~ScavTrap();
};
#endif