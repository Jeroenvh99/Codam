#ifndef ROBOTOMYREQUESTFORM_C
# define ROBOTOMYREQUESTFORM_C
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string target = "something");
		RobotomyRequestForm(const RobotomyRequestForm &old);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &old);
		void execute(Bureaucrat const &executor) const;
		~RobotomyRequestForm();
};
#endif