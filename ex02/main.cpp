#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat rookie("Rookie", 75);
		ShrubberyCreationForm Shrub1("test");
		std::cout << rookie << std::endl << Shrub1 << std::endl;
		rookie.signForm(Shrub1);
		std::cout << Shrub1 << std::endl;
		rookie.executeForm(Shrub1);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
