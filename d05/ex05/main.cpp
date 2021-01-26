#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "OfficeBlock.hpp"
#include "Intern.hpp"
#include <iostream>

int     main()
{
    OfficeBlock block;
    Intern      intern;
    Bureaucrat  signatory("zaphod", 1);
    Bureaucrat  newbie("newbie", 140);
    Bureaucrat  middle("middleman", 55);

    std::cout << "\n\n NEWBIE AND MIDDLE\n";
    block.doBureaucraty("shrubbery creation", "shrub");
    block.setIntern(&intern);
    block.setSignatory(&newbie);
    block.setExecutor(&middle);
    block.doBureaucraty("shrubbery creation", "shrub");
    block.doBureaucraty("robotomy request", "shrub");
    block.doBureaucraty("presidential pardon", "shrub");
    std::cout << "\n\n MIDDLE AND SIGNATORY\n";
    block.setSignatory(&middle);
    block.setExecutor(&signatory);
    block.doBureaucraty("shrubbery creation", "shrub");
    block.doBureaucraty("robotomy request", "shrub");
    block.doBureaucraty("presidential pardon", "shrub");
    std::cout << "\n\nSIGNATORY ALONE\n";
    block.setSignatory(&signatory);
    block.doBureaucraty("shrubbery creation", "shrub");
    block.doBureaucraty("robotomy request", "shrub");
    block.doBureaucraty("presidential pardon", "shrub");
    block.doBureaucraty("presidential coukie", "shrub");
}