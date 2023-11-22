#ifndef CLAPTRAP_C
# define CLAPTRAP_C
# include <string>

class ClapTrap {
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap);
		ClapTrap& operator=(const ClapTrap &clap);
		std::string getName() const;
		unsigned int getEnergy() const;
		unsigned int getHit() const;
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void info() const;
		~ClapTrap();
};
#endif