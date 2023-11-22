#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, "PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old) : AForm(old.getTarget(), "PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &old) {
	(void)old;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecutionGrade())
		throw AForm::GradeTooLowException();
	if (!isSigned())
		throw AForm::NotSignedException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}