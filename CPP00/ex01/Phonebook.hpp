#ifndef PHONEBOOK_C
# define PHONEBOOK_C
# include "Contact.hpp"

class Phonebook {
	private:
		Contact _contacts[8];
		int _index;
	public:
		Phonebook();
		~Phonebook();
		void Add();
		void Search();
};
#endif