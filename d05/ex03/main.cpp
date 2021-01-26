#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int     main()
{
    Intern  intern;
    Form    *shrub;
    Form    *robot;
    Form    *president;

    shrub = intern.makeForm("shrubbery creation", "shrubery");
    std::cout << *shrub << std::endl;

    robot = intern.makeForm("robotomy request", "robotomy");
    std::cout << *robot << std::endl;

    president = intern.makeForm("presidential pardon", "presidentery");
    std::cout << *president << std::endl;

    intern.makeForm("lemon cheesecake", "yohoho");
    delete shrub;
    delete robot;
    delete president;
}