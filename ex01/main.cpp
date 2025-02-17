#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

	std::cout << "\n===== Form Tests! =====" << std::endl;
	try
	{
		std::cout << "Creating a form with signGrade = 0" << std::endl;
		Form f1("ImpossibleForm", 0, 10); // Should throw GradeTooHighException
		std::cout << f1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Creating a form with signGrade = 151" << std::endl;
		Form f2("InvalidForm", 151, 100); // Should throw GradeTooLowException
		std::cout << f2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat topBureaucrat("Mr. Perfect", 1);
		Form f3("TopSecretForm", 2, 50);
		std::cout << topBureaucrat << std::endl << f3 << std::endl;
		topBureaucrat.signForm(f3); // Should succeed
		std::cout << f3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat rookie("Rookie", 75);
		Form f4("MidLevelForm", 50, 50);
		std::cout << rookie << std::endl << f4 << std::endl;
		rookie.signForm(f4); // Should fail if 75 > 50
		std::cout << f4 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
