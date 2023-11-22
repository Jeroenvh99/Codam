#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	Bureaucrat marvin("marv", 25);
	std::cout << marvin << std::endl;
	PresidentialPardonForm pardon("Slartibartfast");
	std::cout << pardon << std::endl;
	try {
		Bureaucrat marvin("marv", 144);
		marvin.signForm(pardon);
		marvin.executeForm(pardon);
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	} try {
		marvin.signForm(pardon);
		marvin.executeForm(pardon);
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	} try {
		PresidentialPardonForm excuseMe("Slartibartfast");
		marvin.executeForm(excuseMe);
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	ShrubberyCreationForm bush("the neighbor's house");
	std::cout << bush << std::endl;
	try {
		marvin.signForm(bush);
		marvin.executeForm(bush);
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	} try {
		marvin.executeForm(pardon);
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
