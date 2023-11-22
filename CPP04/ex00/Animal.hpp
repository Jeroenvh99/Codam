#ifndef ANIMAL_C
# define ANIMAL_C
# include <string>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &animal);
		Animal& operator=(const Animal &animal);
		const std::string getType() const;
		virtual void makeSound() const;
		virtual ~Animal();
};
#endif