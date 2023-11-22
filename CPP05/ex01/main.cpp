#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form release("prisoner release form", 45, 43);
	{
		Bureaucrat marvin("marv", 60);
		std::cout << release << std::endl;
		marvin.signForm(release);
	}
	{
		Bureaucrat marvin("marv", 20);
		marvin.signForm(release);
	}
	Form presidential("presidential prisoner release form", 4, 2);
	{
		Bureaucrat arthur("arthur", 2);
		arthur.signForm(presidential);
		std::cout << presidential << std::endl;
	}
	try {
		Form fake("doesn't work", 2, 0);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form fake("doesn't work", 2, 161);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
