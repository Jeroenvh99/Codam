#include "Phonebook.hpp"
#include <iostream>

int main() {
	Phonebook book = Phonebook();
	std::string option;

	std::cout << "Welcome to my awesome phonebook\n" << std::endl;
	while (option != "EXIT") {
		std::cout << "Please enter one of the following options\n\tADD\n\tSEARCH\n\tEXIT" << std::endl;
		std::getline(std::cin, option);
		if (std::cin.eof())
			break ;
		if (option == "ADD")
			book.Add();
		else if (option == "SEARCH")
			book.Search();
		else if (option == "EXIT")
			std::cout << "Bye bye" << std::endl;
	}
	return 0;
}