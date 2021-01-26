#include "PlasmaRiffle.hpp"
#include <iostream>

PlasmaRiffle::PlasmaRiffle(): AWeapon("Plasma Riffle", 5, 21)
{
	std::cout << "PlasmaRiffle\n";
}

PlasmaRiffle::PlasmaRiffle(PlasmaRiffle const &obj): AWeapon(obj)
{
	*this = obj;
}

PlasmaRiffle::~PlasmaRiffle()
{
	std::cout << "~PlasmaRiffle\n";
}

void					PlasmaRiffle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *\n";
}

PlasmaRiffle			&PlasmaRiffle::operator=(PlasmaRiffle const &rhs)
{
	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();
	return *this;
}
