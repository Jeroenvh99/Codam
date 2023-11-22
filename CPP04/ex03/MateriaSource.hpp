#ifndef MATERIASOURCE_C
# define MATERIASOURCE_C
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_inventory[4];
		AMateria* getMateria(int idx) const;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &materiaSource);
		MateriaSource &operator=(const MateriaSource &materiaSource);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
		~MateriaSource();
};
#endif