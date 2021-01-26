#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const &type): _type(type), _xp(0)
{
	std::cout << "AMateria " << type << " created\n";
}

AMateria::AMateria(AMateria const &obj)
{
	*this = obj;
}

AMateria::~AMateria()
{
	std::cout << "AMateria " << this->_type << " destructed\n";
}

std::string const	&AMateria::getType() const { return this->_type; }
unsigned int		AMateria::getXP() const { return this->_xp; }

void				AMateria::use(ICharacter &target)
{
	this->_xp += 10;
	std::cout << "AMateria used on " << target.getName() << std::endl;
}

AMateria			&AMateria::operator=(AMateria const &rhs)
{
	this->_type = rhs.getType();
	this->_xp = rhs.getXP();
	return *this;
}
