#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
	name("form"),
	isSigned(false),
	signGrade(1),
	executeGrade(1),
	target("Target")
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade, std::string target) :
	name(name),
	isSigned(false),
	signGrade(signGrade),
	executeGrade(executeGrade),
	target(target)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	validateGrade(this->signGrade);
	validateGrade(this->executeGrade);
}

AForm::AForm(const AForm &other) :
	name(other.name),
	isSigned(other.isSigned),
	signGrade(other.signGrade),
	executeGrade(other.executeGrade),
	target(other.target)
{
	std::cout << "Form copy constructor called" << std::endl;
	validateGrade(this->signGrade);
	validateGrade(this->executeGrade);
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

const std::string &AForm::getName() const
{
	return (this->name);
}

bool AForm::getSigned() const
{
	return (this->isSigned);
}

int AForm::getSignGrade() const
{
	return (this->signGrade);
}

int AForm::getExecuteGrade() const
{
	return (this->executeGrade);
}

const std::string &AForm::getTarget() const
{
	return (this->target);
}

bool AForm::validateGrade(const int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (true);
}

void AForm::validateExecution(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	if (!this->getSigned())
		throw FormNotSignedException();
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("grade is too high");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("grade is too low");
}

const char *AForm::FormNotSignedException::what() const noexcept
{
	return ("the Form is not signed");
}

const char *AForm::FileNotOpenException::what() const noexcept
{
	return ("file couldn't be opened");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
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
