#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, "ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &old) : AForm(old.getTarget(), "ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &old) {
	(void)old;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecutionGrade())
		throw AForm::GradeTooLowException();
	if (!isSigned())
		throw AForm::NotSignedException();
	std::ofstream newShrubbery(getTarget() + "_shrubbery");
	newShrubbery << "           *\n         _/ \\_\n        \\     /\n        /_' '_\\\n         /'+ \\\n        / o o \\\n       /  -' *-\\\n      /.  oo+...\\\n     /o- @ o @o' \\\n    *-------------*\n       [_______]\n        \\_____/" << std::endl;
	newShrubbery.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
