#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, unsigned char signGrade, unsigned char execGrade) : _name(name), _signed(false), _signingGrade(signGrade), _executionGrade(execGrade) {
	if (_signingGrade > 150 || _executionGrade > 150)
		throw Form::GradeTooLowException();
	if (_signingGrade == 0 || _executionGrade == 0)
		throw Form::GradeTooHighException();
	_signed = false;
}

Form::Form(const Form &form) : _name(form.getName()), _signingGrade(form.getSigningGrade()), _executionGrade(form.getExecutionGrade()) {
	_signed = form.isSigned();
	std::cout << "Danger: copying over signed status, new form doesn't have to be signed by a bureaucrat" << std::endl;
}

Form &Form::operator=(const Form &form) {
	_signed = form.isSigned();
	std::cout << "Danger: copying over signed status, this form doesn't have to be signed by a bureaucrat" << std::endl;
	return *this;
}

const std::string &Form::getName() const {
	return _name;
}

const bool &Form::isSigned() const {
	return _signed;
}

const unsigned char &Form::getSigningGrade() const {
	return _signingGrade;
}

const unsigned char &Form::getExecutionGrade() const {
	return _executionGrade;
}

void Form::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() > _signingGrade)
		throw Form::GradeTooLowException();
	_signed = true;
}

Form::~Form() {}

std::ostream& operator<<(std::ostream &out, const Form &form) {
	out << "This is a " << form.getName() << ", it requires a grade of " << (int)form.getSigningGrade() << " to be signed and " << (int)form.getExecutionGrade() << " to be executed.\nIt is currently ";
	if (form.isSigned())
		out << "signed.";
	else
		out << "not signed.";
	return out;
}
