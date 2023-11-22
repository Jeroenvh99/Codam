#ifndef CLAPTRAP_C
# define CLAPTRAP_C
# include <string>

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap);
		ClapTrap& operator=(const ClapTrap &clap);
		std::string getName() const;
		void setName(const std::string &name);
		unsigned int getEnergy() const;
		void decreaseEnergy(const int amount);
		unsigned int getHit() const;
		unsigned int getDamage() const;
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void info() const;
		~ClapTrap();
	protected:
		ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
};
#endif