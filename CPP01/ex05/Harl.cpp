#include <iostream>
#include <string>
#include "Harl.hpp"

void Harl::complain(std::string comm) {
	switch(comm) {
		case "DEBUG":
			Harl::debug();
		case "INFO":
			Harl::info();
		case "WARNING":
			Harl::warning();
		case "ERROR":
			Harl::error();
		default:
			std::cout << "You entered a wrong command, that\'s not what I want, try again" << std::endl;
	}
}