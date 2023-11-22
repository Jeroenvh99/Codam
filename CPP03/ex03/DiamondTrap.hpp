#ifndef DIAMONDTRAP_C
# define DIAMONDTRAP_C
# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamond);
		DiamondTrap& operator=(const DiamondTrap &diamond);
		using   ScavTrap::attack;
		void whoAmI();
		~DiamondTrap();
};
#endif