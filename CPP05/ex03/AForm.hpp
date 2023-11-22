#ifndef AFORM_C
# define AFORM_C
# include <string>
# include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string _target;
		const std::string _name;
		bool _signed;
		const unsigned char _signingGrade;
		const unsigned char _executionGrade;
	public:
		AForm(std::string name = "notissued", unsigned char signGrade = 1, unsigned char execGrade = 1);
		AForm(std::string target, std::string name, unsigned char signGrade, unsigned char execGrade);
		AForm(const AForm &aForm);
		AForm &operator=(const AForm &aForm);
		const std::string &getName() const;
		const std::string &getTarget() const;
		const bool &isSigned() const;
		const unsigned char &getSigningGrade() const;
		const unsigned char &getExecutionGrade() const;
		void beSigned(const Bureaucrat &signer);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high, the maximum grade for this form is ";
				}
			};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low, the minimum grade for this form is ";
				}
		};
		class NotSignedException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "This form isn't signed, I don't accept that";
				}
		};
		virtual ~AForm();
};
std::ostream& operator<<(std::ostream &out, const AForm &aForm);
#endif