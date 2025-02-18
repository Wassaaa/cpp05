#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "\n###### ShrubberyCreationForm Tests ######" << std::endl;

	try
	{
		Bureaucrat rookie("Rookie", 75);
		ShrubberyCreationForm shrub1("test");
		std::cout << rookie << std::endl << shrub1 << std::endl;
		rookie.signForm(shrub1);
		std::cout << shrub1 << std::endl;
		rookie.executeForm(shrub1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n###### Test ShrubberyCreationForm File Creation Error ######" << std::endl;
	try
	{
		Bureaucrat highRank("HighRank", 1);
		ShrubberyCreationForm shrub2("/invalid/path/test");
		std::cout << highRank << std::endl << shrub2 << std::endl;
		highRank.signForm(shrub2);
		std::cout << shrub2 << std::endl;
		highRank.executeForm(shrub2);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n###### RobotomyRequestForm Tests ######" << std::endl;

	try
	{
		Bureaucrat highRank("HighRank", 1);
		RobotomyRequestForm robot1("target1");
		std::cout << highRank << std::endl << robot1 << std::endl;
		highRank.signForm(robot1);
		std::cout << robot1 << std::endl;
		highRank.executeForm(robot1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n###### Test RobotomyRequestForm Randomness ######" << std::endl;
	try
	{
		Bureaucrat highRank("HighRank", 1);
		RobotomyRequestForm robot2("target2");
		std::cout << highRank << std::endl << robot2 << std::endl;
		highRank.signForm(robot2);
		std::cout << robot2 << std::endl;

		for (int i = 0; i < 10; ++i)
		{
			highRank.executeForm(robot2);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
