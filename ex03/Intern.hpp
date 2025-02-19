#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	// subclasses
	class FormNotFoundException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};
	
	// functions
	AForm* makeForm(const std::string name, const std::string target);

	AForm* createShrubberyCreationForm(const std::string target);
	AForm* createRobotomyRequestForm(const std::string target);
	AForm* createPresidentialPardonForm(const std::string target);

private:

};

#endif