#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bob;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat bob("bobbie", 0);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat bob("bobbie", 1);
		std::cout << bob << std::endl;
		++bob;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat bob("bobbie", 150);
		std::cout << bob << std::endl;
		--bob;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
