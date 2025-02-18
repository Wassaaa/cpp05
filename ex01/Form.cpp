#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("form"), isSigned(false), signGrade(1), executeGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade) :
	name(name),
	isSigned(false),
	signGrade(signGrade),
	executeGrade(executeGrade)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	validateGrade(this->signGrade);
	validateGrade(this->executeGrade);
}

// copy constructor
Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned),
	signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	validateGrade(this->signGrade);
	validateGrade(this->executeGrade);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

const std::string &Form::getName() const
{
	return (this->name);
}

bool Form::getSigned() const
{
	return (this->isSigned);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecuteGrade() const
{
	return (this->executeGrade);
}

bool Form::validateGrade(const int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (true);
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("grade is too high");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << " ======================================\n"
		<< " |           FORM INFORMATION         |\n"
		<< " ======================================\n"
		<< " Name:            " << form.getName() << "\n"
		<< " Signed:          " << (form.getSigned() ? "Yes" : "No") << "\n"
		<< " Sign Grade:      " << form.getSignGrade() << "\n"
		<< " Execute Grade:   " << form.getExecuteGrade() << "\n"
		<< " ======================================\n";
	return (os);
}
