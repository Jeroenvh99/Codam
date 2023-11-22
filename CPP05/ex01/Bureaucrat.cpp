#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, unsigned char grade) {
	if (grade == 0) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_name = name;
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	_name = bureaucrat.getName();
	_grade = bureaucrat.getGrade();
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

const unsigned char &Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::signForm(Form &form) const {
	try {
	form.beSigned(*this);
	std::cout << _name << " signed " << form.getName() << std::endl;
	} catch(std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because it's " << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator++() {
	if (_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	--_grade;
	return *this;
}

Bureaucrat &Bureaucrat::operator--() {
	if (_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	++_grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << (int)bureaucrat.getGrade();
	return out;
}
