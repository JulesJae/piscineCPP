#include "Decrementp.hpp"

Decrementp::Decrementp(char **head): _head(head)
{
	this->_type = '<';
}

Decrementp::Decrementp(Decrementp const &obj)
{
	*this = obj;
}

Decrementp::~Decrementp()
{

}

int				Decrementp::exec()
{
	(*this->_head)--;
	return IInstruction::OK;
}

Decrementp			&Decrementp::operator=(Decrementp const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
