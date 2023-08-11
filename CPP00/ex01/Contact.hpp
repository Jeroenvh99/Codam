#ifndef CONTACT_C
# define CONTACT_C
# include <string>

class Contact {
	private:
		int _index;
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact();
		Contact(int index);
		Contact(const Contact &contact);
		~Contact();
		Contact& operator=(const Contact &contact);
		std::string Format(std::string in);
		void Display();
		void DisplayDetail();
};
#endif