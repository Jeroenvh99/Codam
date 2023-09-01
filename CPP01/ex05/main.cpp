#include <iostream>
#include <string>
#include "Harl.hpp"

int main() {
	Harl harl;
	std::string in;

	std::cout << "Hi, this is harl speaking, the complaining person." << "Input one of the following commands for me to complain" << std::endl;
	std::cout << "DEBUG\nINFO\nWARNING\nERROR" << std::endl;
	std::cin >> in;
	while (in.compare("EXIT")) {
		harl.complain(in);
		std::cin >> in;
	}
	return 0;
}
