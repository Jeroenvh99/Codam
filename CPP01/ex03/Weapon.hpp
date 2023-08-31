#ifndef WEAPON_C
# define WEAPON_C
# include <string>

class Weapon{
	private:
		std::string _type;
	public:
		Weapon();
		Weapon(const Weapon &weapon);
		Weapon& operator=(const Weapon &weapon);
		const std::string &getType();
		void setType(std::string type);
		~Weapon();
};
#endif
