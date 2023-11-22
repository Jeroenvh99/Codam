#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, unsigned char signGrade, unsigned char execGrade) : _name(name), _signed(false), _signingGrade(signGrade), _executionGrade(execGrade) {
	if (_signingGrade > 150 || _executionGrade > 150)
		throw AForm::GradeTooLowException();
	if (_signingGrade == 0 || _executionGrade == 0)
		throw AForm::GradeTooHighException();
	_signed = false;
}

AForm::AForm(std::string target, std::string name, unsigned char signGrade, unsigned char execGrade) : _target(target), _name(name), _signed(false), _signingGrade(signGrade), _executionGrade(execGrade) {
	if (_signingGrade > 150 || _executionGrade > 150)
		throw AForm::GradeTooLowException();
	if (_signingGrade == 0 || _executionGrade == 0)
		throw AForm::GradeTooHighException();
	_signed = false;
}

AForm::AForm(const AForm &aForm) : _target(aForm.getTarget()), _name(aForm.getName()), _signingGrade(aForm.getSigningGrade()), _executionGrade(aForm.getExecutionGrade()) {
	_signed = aForm.isSigned();
	std::cout << "Danger: copying over signed status, new aForm doesn't have to be signed by a bureaucrat" << std::endl;
}

AForm &AForm::operator=(const AForm &aForm) {
	_signed = aForm.isSigned();
	std::cout << "Danger: copying over signed status, this aForm doesn't have to be signed by a bureaucrat" << std::endl;
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

const std::string &AForm::getTarget() const {
	return _target;
}

const bool &AForm::isSigned() const {
	return _signed;
}

const unsigned char &AForm::getSigningGrade() const {
	return _signingGrade;
}

const unsigned char &AForm::getExecutionGrade() const {
	return _executionGrade;
}

void AForm::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() > _signingGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

AForm::~AForm() {}

std::ostream& operator<<(std::ostream &out, const AForm &aForm) {
	out << "This is a " << aForm.getName() << ", it requires a grade of " << (int)aForm.getSigningGrade() << " to be signed and " << (int)aForm.getExecutionGrade() << " to be executed.\nIt is currently ";
	if (aForm.isSigned())
		out << "signed.";
	else
		out << "not signed.";
	return out;
}