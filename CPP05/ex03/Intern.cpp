#include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
	(void)intern;
}

Intern &Intern::operator=(const Intern &intern) {
	(void)intern;
	return *this;
}

AForm *Intern::ShrubberyFactory(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::RobotomyFactory(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::PresidentialFactory(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	std::string forms[3] {"Shrubberycreationform", "Robotomyrequestform", "Presidentialpardonform"};
	AForm *(Intern::*createForm[3])(std::string target) = {&Intern::ShrubberyFactory, &Intern::RobotomyFactory, &Intern::PresidentialFactory};
	AForm *newForm;
	for (int i = 0; i < 3; i++) {
		if (formName.compare(forms[i]) == 0) {
			newForm = (*this.*createForm[i])(formTarget);
			std::cout << "Intern creates " << newForm->getName() << "." << std::endl;
			return newForm;
		}
	}
	throw Intern::NonExistentForm();
}

Intern::~Intern() {}

std::ostream& operator<<(std::ostream &out, Intern const &intern) {
	(void)intern;
	out << "Hi, I'm an intern, my job here kinda sucks.";
	return out;
}
