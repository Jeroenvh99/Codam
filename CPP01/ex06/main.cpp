#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;
	std::string in;

	std::cout << "Hi, this is harl speaking, the complaining person." << std::endl;
	in = argv[1];
	harl.complain(in);
	return 0;
}
