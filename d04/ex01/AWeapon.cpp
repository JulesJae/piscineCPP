#include "AWeapon.hpp"
#include <iostream>

AWeapon::AWeapon(std::string const &name, int apcost, int damage): apcost(apcost), damage(damage), _name(name)
{
	std::cout << name << " Weapon has been constructed\n";
}

AWeapon::AWeapon(AWeapon const &obj)
{
	*this = obj;
}

AWeapon::~AWeapon()
{
	std::cout << this->_name << " Weapon has been destroyed\n";
}

std::string		AWeapon::getName() const { return this->_name; }
int				AWeapon::getDamage() const { return this->damage; }
int				AWeapon::getAPCost() const { return this->apcost; }

AWeapon			&AWeapon::operator=(AWeapon const &rhs)
{
	this->apcost = rhs.getAPCost();
	this->_name = rhs.getName();
	this->damage = rhs.getDamage();
	return *this;
}
