#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char **argv) {
	char *str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++) {
			str = argv[i];
			for (size_t j = 0; j < strlen(str); j++) {
				std::cout << static_cast<char>(toupper(str[j]));
			}
		}
		std::cout << std::endl;
	}
}