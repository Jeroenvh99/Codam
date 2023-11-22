#ifndef AANIMAL_C
# define AANIMAL_C
# include <string>

class AAnimal {
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(const AAnimal &animal);
		AAnimal& operator=(const AAnimal &animal);
		const std::string &getType() const;
		virtual void makeSound() const = 0;
		virtual ~AAnimal();
};
#endif