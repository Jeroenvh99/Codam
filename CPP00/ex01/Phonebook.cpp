#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>

Phonebook::Phonebook() {
	this->_index = 0;
}

Phonebook::Phonebook( const Phonebook &book ) {}

Phonebook::~Phonebook() {}

Phonebook& Phonebook::operator=( const Phonebook &book ) {
	return *this;
}

void Phonebook::Add() {
	this->_contacts[this->_index] = Contact(this->_index + 1);
	if (this->_index < 7)
		++(this->_index);
}

void Phonebook::Search() {
	int detailindex;

	if (this->_index == 0) {
		std::cout << "There are no contacts to display" << std::endl;
		return;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	for (int i = 0;i < this->_index;i++)
		this->_contacts[i].Display();
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Please input the index of the contact you would like to view in detail" << std::endl;
	std::cin >> detailindex;
	while (detailindex < 1 || detailindex > this->_index + 1) {
		std::cout << "That index doesn't seem to exist, please try again" << std::endl;
		std::cin >> detailindex;
	}
	this->_contacts[detailindex - 1].DisplayDetail();
}