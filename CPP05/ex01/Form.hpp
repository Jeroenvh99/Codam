#ifndef FORM_C
# define FORM_C
# include <string>
# include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const unsigned char _signingGrade;
		const unsigned char _executionGrade;
	public:
		Form(std::string name = "notissued", unsigned char signGrade = 1, unsigned char execGrade = 1);
		Form(const Form &form);
		Form &operator=(const Form &form);
		const std::string &getName() const;
		const bool &isSigned() const;
		const unsigned char &getSigningGrade() const;
		const unsigned char &getExecutionGrade() const;
		void beSigned(const Bureaucrat &signer);
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high, the maximum grade for a form is 1";
				}
			};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low, the minimum grade for a form is 150";
				}
		};
		~Form();
};
std::ostream& operator<<(std::ostream &out, const Form &form);
#endif