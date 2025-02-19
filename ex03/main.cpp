#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <sstream>
#include <streambuf>

int main()
{
	std::cout << "\n###### Intern Tests ######" << std::endl;
    try
    {
        Bureaucrat boss("Boss", 1);
        Intern intern;

        AForm* f1 = intern.makeForm("shrubbery creation", "Home");
        std::cout << "\nCreated form: " << f1->getName() << std::endl;
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
		std::cout << std::endl;

        AForm* f2 = intern.makeForm("robotomy request", "Robot");
        std::cout << "\nCreated form: " << f2->getName() << std::endl;
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
		std::cout << std::endl;

        AForm* f3 = intern.makeForm("presidential pardon", "PardonedOne");
        std::cout << "\nCreated form: " << f3->getName() << std::endl;
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
		std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
