#include "Span.hpp"
#include <iostream>
#include <ctime>

void    initialize_span(Span    &s, unsigned int size)
{
    unsigned int    i;

    for (i = 0; i < size; i++)
        s.addNumber(rand() % 1000);
    s.printSortedArray();
}

int     main()
{
    Span    s(15);
    Span    s2(150);
    Span    s3(1500);

    std::srand(std::time(nullptr));
    try
    {
        std::cout << "\n\n ******************* \n\n\n";
        initialize_span(s, 15);
        std::cout << "s[15] => Smallest span = " << s.shortestSpan() << "\n";
        std::cout << "s[15] = > longets span = " << s.longestSpan() << "\n";
        std::cout << "\n\n ******************* \n\n\n";
        initialize_span(s2, 150);
        std::cout << "s[150] => Smallest span = " << s2.shortestSpan() << "\n";
        std::cout << "s[150] = > longets span = " << s2.longestSpan() << "\n";
        std::cout << "\n\n ******************* \n\n\n";
        initialize_span(s3, 1500);
        std::cout << "s[1500] => Smallest span = " << s3.shortestSpan() << "\n";
        std::cout << "s[1500] = > longets span = " << s3.longestSpan() << "\n";
        s.addNumber(150);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Nice catch\n";
    }
    return (0);
}