#include <iostream>
#include "Victim.hpp"
#include "Derived.hpp"
#include "Peon.hpp"
#include "Sorcerer.hpp"

int main()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
    Derived billy("Billy");
    
    std::cout << robert << jim << joe << billy;
    robert.polymorph(jim);
    robert.polymorph(joe);
    robert.polymorph(billy);
    return 0;
}