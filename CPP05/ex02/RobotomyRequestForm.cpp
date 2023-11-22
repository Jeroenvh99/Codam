#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, "shrubberycreationform", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old) : AForm(old.getTarget(), "shrubberycreationform", 72, 45) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &old) {
	(void)old;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecutionGrade())
		throw AForm::GradeTooLowException();
	if (!isSigned())
		throw AForm::NotSignedException();
	srand((unsigned)time(0));
	int tries = rand() % 2;
	if (tries % 2 == 1)
		std::cout << getTarget() << " has been succesfully robotomized." << std::endl;
	else
		std::cout << "robotomization has failed, try again later." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}