#include "Bureaucrat.hpp"
#include <iostream>

int     main()
{
    Bureaucrat  billy("Billy");
    Bureaucrat  boss("Boss", 1);
    

    std::cout << billy;
    std::cout << boss;
    try 
    {
        // Bureaucrat high("high", 0);
        // Bureaucrat low("low", 151);

        billy.upGrade();
        std::cout << billy;
        billy.downGrade();
        // billy.downGrade();
        boss.downGrade();
        std::cout << boss;
        boss.upGrade();
        boss.upGrade();
    } catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }
}