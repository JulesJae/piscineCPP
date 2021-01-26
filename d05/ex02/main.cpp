#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int     main()
{
    Form    *s = new ShrubberyCreationForm("SchrubForm");
    Form    *p = new PresidentialPardonForm("PresidentForm");
    Form    *r = new RobotomyRequestForm("BotForm");
    Bureaucrat  zafod("Zafod Beeblerox", 1);
    Bureaucrat  robot("Mister Robot", 44);
    Bureaucrat  shrub("Cofee Maker", 137);

    try
    {
        s->beSigned(shrub);
        // p->beSigned(shrub);
        r->beSigned(robot);
        // p->beSigned(robot);
        s->beSigned(zafod);
        p->beSigned(zafod);
        r->beSigned(zafod);
        shrub.executeForm(*s);
        shrub.executeForm(*r);
        shrub.executeForm(*p);
        robot.executeForm(*s);
        robot.executeForm(*r);
        robot.executeForm(*p);
        zafod.executeForm(*s);
        zafod.executeForm(*r);
        zafod.executeForm(*p);
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}