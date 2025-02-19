#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	public:
		// constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;
		~PresidentialPardonForm();

		// functions
		void execute(const Bureaucrat& bureaucrat) const override;

	private:

};

#endif
