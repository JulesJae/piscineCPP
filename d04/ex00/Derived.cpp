#include "Derived.hpp"
#include <string>
#include <iostream>

Derived::Derived(std::string const &name): Victim(name) 
{
	std::cout << "Salut la compagnie, je suis " << name << " le Francais.\n";
}

Derived::Derived(Derived const &obj): Victim(obj)
{
	*this = obj;
}

Derived::~Derived()
{
	std::cout << ":'(\n";
}

void			Derived::getPolymorphed() const
{
	std::cout << this->name << " was just turned into into a yellow mustard hot dog!\n";
}


Derived			&Derived::operator=(Derived const &rhs)
{
	this->name = rhs.name;
	return *this;
}
