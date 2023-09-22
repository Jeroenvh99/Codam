#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv) {
	std::string str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++) {
			str = argv[i];
			for (size_t j = 0; j < str.size(); j++) {
				std::cout << static_cast<char>(std::toupper(str[j]));
			}
			if (i < argc) {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
}