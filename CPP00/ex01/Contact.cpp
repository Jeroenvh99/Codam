#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("") {}

Contact::Contact( const Contact &contact ) {}

Contact& Contact::operator=( const Contact &contact ) {
	_firstName = contact._firstName;
	_lastName = contact._lastName;
	_nickname = contact._nickname;
	_phoneNumber = contact._phoneNumber;
	_darkestSecret = contact._darkestSecret;
	return *this;
}

void Contact::Fill() {
	_firstName = "";
	while (_firstName == "") {
		std::cout << "Enter your first name:" << std::endl;
		std::getline(std::cin, _firstName);
	}
	_lastName = "";
	while (_lastName == "") {
		std::cout << "Enter your last name:" << std::endl;
		std::getline(std::cin, _lastName);
	}
	_nickname = "";
	while (_nickname == "") {
		std::cout << "Enter your nickname:" << std::endl;
		std::getline(std::cin, _nickname);
	}
	_phoneNumber = "";
	while (_phoneNumber == "") {
		std::cout << "Enter your phonenumber:" << std::endl;
		std::getline(std::cin, _phoneNumber);
	}
	_darkestSecret = "";
	while (_darkestSecret == "") {
		std::cout << "Enter your darkest secret, if you dare:" << std::endl;
		std::getline(std::cin, _darkestSecret);
	}
}

void Contact::Display(int index) {
	std::string first = _firstName;
	std::string last = _lastName;
	std::string nick = _nickname;
	if (first.length() > 10)
		first = _firstName.substr(0, 9) + '.';
	if (last.length() > 10)
		first = _lastName.substr(0, 9) + '.';
	if (nick.length() > 10)
		nick = _nickname.substr(0, 9) + '.';
	std::cout << "|" << std::setw(10) << index << "|" << std::setw(10) << first << "|"
	<< std::setw(10) << last << "|" << std::setw(10) << nick << "|" << std::endl;
}

void Contact::DisplayDetail(int index) {
	std::cout << "Index: " << index << "\nFirst name: " << _firstName << "\nLast name: "
	<< _lastName << "\nNickname: " << _nickname << "\nPhone number: "
	<< _phoneNumber << "\nDarkest secret: " << _darkestSecret << std::endl;
}

Contact::~Contact() {}