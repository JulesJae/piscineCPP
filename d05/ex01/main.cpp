#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int     main()
{
    Form    form("form", 12, 5);
    Bureaucrat  Josh("josh", 13);

    try 
    {
        std::cout << form << std::endl;
        std::cout << Josh << std::endl;
        Josh.upGrade();
        form.beSigned(Josh);
        form.beSigned(Josh);
        // Josh.downGrade();
        form.beSigned(Josh);
        // form.setSignGrade(151);
        // form.setExecGrade(0);
        std::cout << form << std::endl;
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
}