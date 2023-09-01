#ifndef ZOMBIE_C
# define ZOMBIE_C
# include <string>

class Zombie{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(const Zombie &zombie);
		Zombie& operator=(const Zombie &zombie);
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void randomChump(std::string name);
};
#endif