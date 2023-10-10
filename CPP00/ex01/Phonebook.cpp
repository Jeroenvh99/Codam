#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>

Phonebook::Phonebook() {
	this->_index = -1;
	this->_length = 0;
}

Phonebook::Phonebook( const Phonebook &book ) {}

Phonebook& Phonebook::operator=( const Phonebook &book ) {
	return *this;
}

void Phonebook::Add() {
	_index = (_index + 1) % 8;
	if (_length < 8)
		++_length;
	_contacts[_index].Fill();
}

void Phonebook::Search() {
	std::string tmp;
	int detailindex;

	if (this->_index == -1) {
		std::cout << "There are no contacts yet, add some first" << std::endl;
		return;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].Display(i);
	std::cout << "---------------------------------------------" << std::endl;
	while (tmp == "" || tmp[0] < '0' || tmp[0] > this->_length + '0') {
		std::cout << "Please input the index of the contact you would like to view in detail" << std::endl;
		std::getline(std::cin, tmp);
	}
	detailindex = std::stoi(tmp);
	this->_contacts[detailindex].DisplayDetail(detailindex);
}

Phonebook::~Phonebook() {}