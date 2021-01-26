#include "Peon.hpp"
#include <string>
#include <iostream>

Peon::Peon(std::string const &name): Victim(name) 
{
	std::cout << "Zog zog.\n";
}

Peon::Peon(Peon const &obj): Victim(obj)
{
	*this = obj;
}

Peon::~Peon()
{
	std::cout << "Bleuark...\n";
}

void			Peon::getPolymorphed() const
{
	std::cout << this->name << " was just turned into into a pink pony!\n";
}


Peon			&Peon::operator=(Peon const &rhs)
{
	this->name = rhs.name;
	return *this;
}
