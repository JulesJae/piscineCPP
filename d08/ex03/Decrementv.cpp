#include "Decrementv.hpp"

Decrementv::Decrementv(char **head): _head(head)
{
	this->_type = '-';
}

Decrementv::Decrementv(Decrementv const &obj)
{
	*this = obj;
}

Decrementv::~Decrementv()
{

}

int				Decrementv::exec()
{
	(**this->_head)--;
	return IInstruction::OK;
}

Decrementv			&Decrementv::operator=(Decrementv const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
