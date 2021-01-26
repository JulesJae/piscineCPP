#include "Sorcerer.hpp"
#include <iostream>
#include "Victim.hpp"

Sorcerer::Sorcerer(std::string const &name, std::string const &title): name(name), title(title)
{
	std::cout << name << ", " << title << ", is born!\n";
}

Sorcerer::Sorcerer(Sorcerer const &obj)
{
	*this = obj;
}

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!\n";
}

void				Sorcerer::polymorph(Victim const &vicos) const
{
	vicos.getPolymorphed();
}

Sorcerer			&Sorcerer::operator=(Sorcerer const &rhs)
{
	this->name = rhs.name;
	this->title = rhs.title;
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Sorcerer const &sorcerer)
{
	o << "I am "<< sorcerer.name << ", " << sorcerer.title << ", and i like ponies!\n";
	return o;
}