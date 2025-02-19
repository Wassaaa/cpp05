#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

//copy constructor
Intern::Intern(const Intern& other)
{
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}

//copy assignment
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy assignment called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
	static const int formCount = 3;
    AForm* (Intern::*formBuilders[formCount])(const std::string) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};
	std::string formNames[formCount] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < formCount; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formBuilders[i])(target);
		}
	}
	throw FormNotFoundException();
}

AForm* Intern::createShrubberyCreationForm(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string target)
{
    return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFoundException::what() const noexcept
{
    return "Form not found";
}
