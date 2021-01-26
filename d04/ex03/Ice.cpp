#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice created\n";
}

Ice::Ice(Ice const &obj): AMateria(obj)
{
	*this = obj;
}

Ice::~Ice()
{
	std::cout << "Ice destructed\n";
}

AMateria	*Ice::clone() const
{
	std::cout << "Ice cloned\n";
	return new Ice(*this);
}

void			Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice			&Ice::operator=(Ice const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
