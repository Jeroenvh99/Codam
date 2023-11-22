#ifndef PRESIDENTIALPARDONFORM_C
# define PRESIDENTIALPARDONFORM_C
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string target = "someone");
		PresidentialPardonForm(const PresidentialPardonForm &old);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &old);
		void execute(Bureaucrat const &executor) const;
		~PresidentialPardonForm();
};
#endif