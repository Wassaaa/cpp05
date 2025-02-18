#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>
#include <streambuf>

int main()
{
	std::cout << "\n###### Running Robotomy Randomness Test ######" << std::endl;
	int successes = 0;
	const int numTests = 1000;

	// Redirect cout to a stringstream
	std::stringstream buffer;
	std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

	try
	{
		Bureaucrat tester("Tester", 1);
		RobotomyRequestForm robot("StatisticalTarget");
		tester.signForm(robot);

		for (int i = 0; i < numTests; ++i)
		{
			buffer.str(std::string()); // Clear the buffer
			robot.execute(tester);
			if (buffer.str().find("successfully") != std::string::npos)
				successes++;
		}
	}
	catch (const std::exception &e)
	{
		std::cout.rdbuf(old); // Restore cout
		std::cout << "Test setup failed: " << e.what() << std::endl;
		return 1;
	}

	// Restore cout
	std::cout.rdbuf(old);

	float successRate = (float)successes / numTests * 100;
	std::cout << "\n###### Robotomy Statistical Results ######" << std::endl;
	std::cout << "After " << numTests << " attempts:" << std::endl;
	std::cout << "Success rate: " << successRate << "% (Expected: 50%)" << std::endl;
	std::cout << "Successes: " << successes << std::endl;
	std::cout << "Failures: " << numTests - successes << std::endl << std::endl;

	std::cout << "\n###### General Constructor and Copy Tests ######" << std::endl;
	try
	{
		ShrubberyCreationForm original("garden");
		ShrubberyCreationForm copy(original);

		std::cout << "Original form:" << std::endl;
		std::cout << original << std::endl;
		std::cout << "Copied form:" << std::endl;
		std::cout << copy << std::endl;

		// Test if copying maintains the signed status
		Bureaucrat boss("Boss", 1);
		boss.signForm(original);
		ShrubberyCreationForm copyAfterSign(original);

		std::cout << "Original after signing:" << std::endl;
		std::cout << original << std::endl;
		std::cout << "Copy after original was signed:" << std::endl;
		std::cout << copyAfterSign << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

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

	std::cout << "\n###### PresidentialPardonForm Basic Test ######" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon1("Criminal1");
		std::cout << president << std::endl << pardon1 << std::endl;
		president.signForm(pardon1);
		president.executeForm(pardon1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n###### PresidentialPardonForm Grade Too Low Test ######" << std::endl;
	try
	{
		Bureaucrat clerk("Clerk", 30);
		PresidentialPardonForm pardon2("Criminal2");
		std::cout << clerk << std::endl << pardon2 << std::endl;
		clerk.signForm(pardon2);  // Should work (grade 25 needed)
		clerk.executeForm(pardon2);  // Should fail (grade 5 needed)
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n###### PresidentialPardonForm Unsigned Execution Test ######" << std::endl;
	try
	{
		Bureaucrat vicePresident("Vice President", 3);
		PresidentialPardonForm pardon3("Criminal3");
		std::cout << vicePresident << std::endl << pardon3 << std::endl;
		// Try to execute without signing
		vicePresident.executeForm(pardon3);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
