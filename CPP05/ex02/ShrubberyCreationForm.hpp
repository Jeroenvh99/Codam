#ifndef SHRUBBERYCREATIONFORM_C
# define SHRUBBERYCREATIONFORM_C
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string target = "somewhere");
		ShrubberyCreationForm(const ShrubberyCreationForm &old);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &old);
		void execute(Bureaucrat const &executor) const;
		~ShrubberyCreationForm();
};
#endif