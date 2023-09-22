#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() {
	this->_index = 0;
}

Contact::Contact(int index) {
	this->_index = index;
	std::cout << "Enter your first name:" << std::endl;
	std::cin >> this->_firstName;
	std::cout << "Enter your last name:" << std::endl;
	std::cin >> this->_lastName;
	std::cout << "Enter your nickname:" << std::endl;
	std::cin >> this->_nickname;
	std::cout << "Enter your phonenumber:" << std::endl;
	std::cin >> this->_phoneNumber;
	std::cout << "Enter your darkest secret, if you dare:" << std::endl;
	std::cin >> this->_darkestSecret;
}

Contact::Contact( const Contact &contact ) {}

Contact& Contact::operator=( const Contact &contact ) {
	return *this;
}

std::string Contact::Format(std::string in) {
	int len;

	len = in.length();
	if (len <= 10) {
		in.insert(0, 10 - len, ' ');
	} else {
		in.resize(10);
		in.at(9) = '.';
	}
	return in;
}

void Contact::Display() {
	std::cout << "|" << "         " << this->_index << "|" << Contact::Format(this->_firstName) << "|" << Contact::Format(this->_lastName) << "|" << Contact::Format(this->_nickname) << "|" << std::endl;
}

void Contact::DisplayDetail() {
	std::cout << "Index: " << this->_index << "\nFirst name: " << this->_firstName << "\nLast name: " << this->_lastName << "\nNickname: " << this->_nickname << "\nPhone number: " << this->_phoneNumber << "\nDarkest secret: " << this->_darkestSecret << std::endl;
}

Contact::~Contact() {}