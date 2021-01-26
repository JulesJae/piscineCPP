#include "Incrementv.hpp"

Incrementv::Incrementv(char **head): _head(head)
{
	this->_type = '+';
}

Incrementv::Incrementv(Incrementv const &obj)
{
	*this = obj;
}

Incrementv::~Incrementv()
{

}

int				Incrementv::exec()
{
	(**this->_head)++;
	return IInstruction::OK;
}

Incrementv			&Incrementv::operator=(Incrementv const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
