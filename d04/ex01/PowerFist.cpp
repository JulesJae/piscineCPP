#include "PowerFist.hpp"
#include <iostream>

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50)
{
	std::cout << "PowerFist\n";
}

PowerFist::PowerFist(PowerFist const &obj): AWeapon(obj)
{
	*this = obj;
}

PowerFist::~PowerFist()
{
	std::cout << "~PowerFist\n";
}

void					PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM !\n";
}

PowerFist			&PowerFist::operator=(PowerFist const &rhs)
{
	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();
	return *this;
}
