#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name): _name(name), _weapon(nullptr) {}

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(&weapon) {}

void HumanA::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}