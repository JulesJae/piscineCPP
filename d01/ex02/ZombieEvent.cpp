#include <iostream>
#include <string>
#include "ZombieEvent.hpp"
#include <ctime>

char const *ZombieEvent::_names[] = { "Philidor", "Anand", "Karpov", "Kasparov", "Fischer", "Laskin" };

ZombieEvent::ZombieEvent(): _type("Fun")
{}

void ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}
Zombie *ZombieEvent::newZombie(std::string name) const
{
    return new Zombie(name, this->_type);
}

Zombie *ZombieEvent::randomChump() const
{
    int     random;
    int     size;
    Zombie  *zombie;

    std::srand(std::time(nullptr));
    size = sizeof(this->_names) / sizeof(char*);
    random = std::rand() % size;
    zombie = this->newZombie(this->_names[random]);
    zombie->advert();
    return zombie;
}