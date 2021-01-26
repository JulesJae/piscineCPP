#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(): name("no name"), type("Faya")
{
    
}

Zombie::Zombie(std::string name, std::string type): name(name), type(type)
{
    std::cout << this->name << " is in da street\n";
}

Zombie::~Zombie()
{
    std::cout << "OH my god " << this->name << " is DEAD :'( (weird for a zombie ...)\n";
}

void Zombie::advert() const
{
    std::cout << "Hello I'm " << this->name << " a " << this->type << " zombie shulololo\n";
}