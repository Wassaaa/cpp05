#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <random>
# include "AForm.hpp"

class Bureaucrat;
class RobotomyRequestForm : public AForm
{
	public:
		// constructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
		~RobotomyRequestForm();

		// functions
		void execute(const Bureaucrat& bureaucrat) const override;

	private:

};

#endif
