#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;
class Form
{
	public:
		// constructors
		Form();
		Form(const std::string name, const int signGrade, const int executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other) = delete;
		~Form();
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
		void beSigned(const Bureaucrat& bureaucrat);

		// getters
		const std::string& getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
		bool validateGrade(const int grade) const;

};

std::ostream& operator<<(std::ostream &os, const Form& form);

#endif
