#include "Victim.hpp"
#include <iostream>

Victim::Victim(std::string const &name): name(name)
{
	std::cout << "A random victim called " << name << " just appeared!\n";
}

Victim::Victim(Victim const &obj)
{
	*this = obj;
}

Victim::~Victim()
{
	std::cout << "The victim " << this->name << " died for no apparent reasons!\n";
}

void			Victim::getPolymorphed() const
{
	std::cout << this->name << " was just turned into in a cute little sheep!\n";
}


Victim			&Victim::operator=(Victim const &rhs)
{
	this->name = rhs.name;
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Victim const &vikos)
{
	o << "I am "<< vikos.name << " and I like otters!\n";
	return o;
}