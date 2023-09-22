#ifndef ZOMBIE_C
# define ZOMBIE_C
# include <string>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		void announce(void);
		void randomChump(std::string name);
		~Zombie();
};
#endif