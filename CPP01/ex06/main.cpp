#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;

	if (argc == 1)
		return 1;
	std::cout << "Hi, this is harl speaking, the complaining person." << std::endl;
	harl.complain(argv[1]);
	return 0;
}
