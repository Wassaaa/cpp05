#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <sstream>
#include <streambuf>

int main()
{
    std::cout << "\n###### Intern Tests ######" << std::endl;
    Bureaucrat boss("Boss", 1);
    Intern intern;

    // Test shrubbery creation form
    try {
        std::cout << "\n--- Testing shrubbery creation form ---" << std::endl;
        AForm *f1 = intern.makeForm("shrubbery creation", "Home");
        std::cout << "Created form: " << f1->getName() << std::endl;
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test robotomy request form
    try {
        std::cout << "\n--- Testing robotomy request form ---" << std::endl;
        AForm *f2 = intern.makeForm("robotomy request", "Robot");
        std::cout << "Created form: " << f2->getName() << std::endl;
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test presidential pardon form
    try {
        std::cout << "\n--- Testing presidential pardon form ---" << std::endl;
        AForm *f3 = intern.makeForm("presidential pardon", "PardonedOne");
        std::cout << "Created form: " << f3->getName() << std::endl;
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test non-existent form (should fail)
    try {
        std::cout << "\n--- Testing non-existent form ---" << std::endl;
        AForm *f4 = intern.makeForm("coffee order", "CoffeeShop");
        std::cout << "Created form: " << f4->getName() << std::endl; // Should not reach here
        boss.signForm(*f4);
        boss.executeForm(*f4);
        delete f4;
    }
    catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
