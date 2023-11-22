#ifndef INTERN_C
# define INTERN_C
# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class Intern {
	private:
		AForm *ShrubberyFactory(std::string target);
		AForm *RobotomyFactory(std::string target);
		AForm *PresidentialFactory(std::string target);
	public:
		Intern();
		Intern(const Intern &intern);
		Intern &operator=(const Intern &intern);
		AForm *makeForm(std::string formName, std::string formTarget);
		class NonExistentForm : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "I don't have the power to make this kind of form";
				}
		};
		~Intern();
};
std::ostream& operator<<(std::ostream &out, const Intern &intern);
#endif