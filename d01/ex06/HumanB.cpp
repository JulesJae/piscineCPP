#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name) {}

HumanB::HumanB(std::string name, Weapon &weapon): _name(name), _weapon(&weapon) {}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}