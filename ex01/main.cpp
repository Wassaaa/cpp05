#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\n##### Form Tests! #####" << std::endl;

	std::cout << "\n##### Test 1: Creating a form with signGrade = 0 #####" << std::endl;
	try
	{
		Form f1("ImpossibleForm", 0, 10); // Should throw GradeTooHighException
		std::cout << f1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n##### Test 2: Creating a form with signGrade = 151 #####" << std::endl;
	try
	{
		Form f2("InvalidForm", 151, 100); // Should throw GradeTooLowException
		std::cout << f2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n##### Test 3: Signing a form with a top bureaucrat #####" << std::endl;
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

	std::cout << "\n##### Test 4: Signing a form with a rookie bureaucrat #####" << std::endl;
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

	std::cout << "\n##### Test 5: Incrementing grade to sign a form #####" << std::endl;
	try
	{
		Bureaucrat climber("Climber", 55);
		Form f5("MidLevelForm", 50, 50);
		std::cout << climber << std::endl << f5 << std::endl;
		climber.signForm(f5);

		while (!f5.getSigned())
		{
			climber.incrementGrade();
			std::cout << "Incrementing grade: " << std::endl;
			std::cout << climber << std::endl << f5 << std::endl;
			climber.signForm(f5);
		}
		std::cout << f5 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
