#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine() 
{
	std::cout << "Tactical Marine ready for action !\n";
}

TacticalMarine::TacticalMarine(TacticalMarine const &obj)
{
	*this = obj;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh ...\n";
}

ISpaceMarine			*TacticalMarine::clone() const
{
	return new TacticalMarine(*this);
}

void					TacticalMarine::battleCry() const
{
	std::cout <<  "For the Holy PLOT !\n";
}

void					TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with a chainsword *\n";
}

void					TacticalMarine::rangedAttack() const
{
	std::cout <<  "* attacks with a bolter *\n";
}

TacticalMarine		&TacticalMarine::operator=(TacticalMarine const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}