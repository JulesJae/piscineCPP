#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion(): Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(RadScorpion const &obj): Enemy(obj)
{
	*this = obj;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *\n";
}

RadScorpion			&RadScorpion::operator=(RadScorpion const &rhs)
{
	this->hp = rhs.getHP();
	return *this;
}
