#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant(): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Break everything !\n";
}

SuperMutant::SuperMutant(SuperMutant const &obj): Enemy(obj)
{
	*this = obj;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ...\n";
}

void				SuperMutant::getDamage(int damage)
{
	Enemy::getDamage(damage - 3);
}

SuperMutant			&SuperMutant::operator=(SuperMutant const &rhs)
{
	this->hp = rhs.getHP();
	return *this;
}
