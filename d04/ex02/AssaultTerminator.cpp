#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator() 
{
	std::cout << "* teleports from space *\n";
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &obj)
{
	*this = obj;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back ...\n";
}

ISpaceMarine			*AssaultTerminator::clone() const
{
	return new AssaultTerminator(*this);
}

void					AssaultTerminator::battleCry() const
{
	std::cout <<  "This code is unclean. Purify it !\n";
}

void					AssaultTerminator::meleeAttack() const
{
	std::cout << "* attaque with chainfists *\n";
}

void					AssaultTerminator::rangedAttack() const
{
	std::cout <<  "* does nothing *\n";
}

AssaultTerminator		&AssaultTerminator::operator=(AssaultTerminator const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

