#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern me;
	Bureaucrat boss("Hugo", 1);
	AForm *form;
	try {
		form = me.makeForm("Shrubberycreationform", "Codam");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		boss.signForm(*form);
		boss.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete form;
	try {
		form = me.makeForm("hereyougo", "home");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		form = me.makeForm("Presidentialpardonform", "Tim");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		boss.signForm(*form);
		std::cout << *form << std::endl;
		boss.executeForm(*form);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete form;
	return 0;
}
