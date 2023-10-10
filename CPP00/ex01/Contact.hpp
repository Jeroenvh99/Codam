#ifndef CONTACT_C
# define CONTACT_C
# include <string>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact();
		Contact(const Contact &contact);
		Contact& operator=(const Contact &contact);
		void Fill();
		void Display(int index);
		void DisplayDetail(int index);
		~Contact();
};
#endif