#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bueraucrat"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	validateGrade(this->grade);
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	validateGrade(this->grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("grade is too low");
}

void Bureaucrat::incrementGrade()
{
	validateGrade(this->grade - 1);
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	validateGrade(this->grade + 1);
	this->grade++;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}
}

const std::string &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

bool Bureaucrat::validateGrade(const int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return true;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << " ======================================\n"
		<< " |         BUREAUCRAT DETAILS         |\n"
		<< " |             ┌( ಠ_ಠ)┘              |\n"
		<< " ======================================\n"
		<< " Name:   "  << bureaucrat.getName()   << "\n"
		<< " Grade:  "  << bureaucrat.getGrade()  << "\n"
		<< " ======================================\n";
	return os;
}
