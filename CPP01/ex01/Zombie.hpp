#ifndef ZOMBIE_C
# define ZOMBIE_C
# include <string>

class Zombie{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(const Zombie &zombie);
		Zombie(std::string name);
		Zombie& operator=(const Zombie &zombie);
		void announce(void);
		Zombie *zombieHorde(int N, std::string name);
		~Zombie();
};
#endif