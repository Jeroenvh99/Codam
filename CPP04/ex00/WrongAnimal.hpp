#ifndef WRONGANIMAL_C
# define WRONGANIMAL_C
# include <string>

class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wrongAnimal);
		WrongAnimal& operator=(const WrongAnimal &wrongAnimal);
		const std::string getType() const;
		void makeSound() const;
		~WrongAnimal();
};
#endif