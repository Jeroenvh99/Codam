#ifndef ZOMBIE_C
# define ZOMBIE_C
# include <string>

class Zombie{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		Zombie(const Zombie &zombie);
		Zombie& operator=(const Zombie &zombie);
		~Zombie();
		void announce(void);
		void setName(std::string name);
};
#endif