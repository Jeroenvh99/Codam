#ifndef BUREAUCRAT_C
# define BUREAUCRAT_C
# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class Bureaucrat {
	private:
		std::string _name;
		unsigned char _grade;
	public:
		Bureaucrat(std::string name = "nameless", unsigned char grade = 150);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);
		const std::string &getName() const;
		const unsigned char &getGrade() const;
		void signForm(AForm &form) const;
		void executeForm(AForm const &form) const;
		Bureaucrat &operator++();
		Bureaucrat &operator--();
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high, the maximum grade is 1";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low, the minimum grade is 150";
				}
		};
		~Bureaucrat();
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif