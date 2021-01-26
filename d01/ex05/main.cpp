#include "Human.hpp"
#include <iostream>

int main()
{
    Human bob;

    std::cout << bob.identifier() << std::endl;
    std::cout << bob.getBrain().identifier() << std::endl;
    return (0);
}