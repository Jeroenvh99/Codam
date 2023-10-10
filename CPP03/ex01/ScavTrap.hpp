#ifndef SCAVTRAP_C
# define SCAVTRAP_C
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &scav);
		ScavTrap& operator=(const ScavTrap &scav);
		void guardGate();
		~ScavTrap();
};
#endif