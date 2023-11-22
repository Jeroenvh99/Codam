#ifndef BRAIN_C
# define BRAIN_C
# include <string>

class Brain {
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		Brain& operator=(const Brain &brain);
		void setIdea(std::string idea, int index);
		const std::string &getIdea(int index) const;
		~Brain();
};
#endif