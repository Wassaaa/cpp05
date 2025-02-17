#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Bureaucrat
{
public:
	// constructors
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other) = delete;
	~Bureaucrat();

	// subclasses
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};

	// functions
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);

	// getters
	const std::string& getName() const;
	int getGrade() const;

private:
	const std::string name;
	int grade;
	bool validateGrade(const int grade) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
