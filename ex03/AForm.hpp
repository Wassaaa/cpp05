#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>

class Bureaucrat;
class AForm
{
public:
	// constructors
	AForm(const std::string name, const int signGrade, const int executeGrade, std::string target);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other) = delete;
	virtual ~AForm();
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
	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
	class FileNotOpenException : public std::exception
	{
		public:
			const char* what() const noexcept override;
	};
	// functions
	virtual void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& bureaucrat) const = 0;
	bool validateGrade(const int grade) const;
	void validateExecution(const Bureaucrat& bureaucrat) const;

	// getters
	const std::string& getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	const std::string& getTarget() const;

protected:
	AForm();

private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
	std::string target;

};

std::ostream& operator<<(std::ostream &os, const AForm& form);

#endif
