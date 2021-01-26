#include "Pony.hpp"
#include <iostream>
#include <new>

void    poneyOnTheHeap()
{
    Pony *pony_heap = new Pony("Beny", 3, 79, Pony::RED);

    pony_heap->jump();
    delete pony_heap;
}

void    poneyOnTheStack() 
{
    Pony poney_stack("Ouioui", 16, 196, Pony::BROWN);

    poney_stack.jump();
}

int     main()
{
    poneyOnTheStack();
    poneyOnTheHeap();
    return (0);
}