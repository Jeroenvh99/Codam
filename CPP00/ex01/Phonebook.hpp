#ifndef PHONEBOOK_C
# define PHONEBOOK_C
# include "Contact.hpp"

class Phonebook {
	private:
		Contact _contacts[8];
		int _index;
		int _length;
	public:
		Phonebook();
		Phonebook(const Phonebook &book);
		Phonebook& operator=(const Phonebook &book);
		void Add();
		void Search();
		~Phonebook();
};
#endif