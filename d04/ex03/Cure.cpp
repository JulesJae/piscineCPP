#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure created\n";
}

Cure::Cure(Cure const &obj): AMateria(obj)
{
	*this = obj;
}

Cure::~Cure()
{
	std::cout << "Cure destructed\n";
}

AMateria		*Cure::clone() const
{
	std::cout << "Cure cloned\n";
	return new Cure(*this);
}

void			Cure::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}

Cure			&Cure::operator=(Cure const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
