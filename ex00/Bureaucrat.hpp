#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other) = delete;
	~Bureaucrat();

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

	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	bool validateGrade(const int grade) const;

private:
	const std::string name;
	int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
