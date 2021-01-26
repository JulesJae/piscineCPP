#include "Incrementp.hpp"

Incrementp::Incrementp(char **head): _head(head)
{
	this->_type = '>';
}

Incrementp::Incrementp(Incrementp const &obj)
{
	*this = obj;
}

Incrementp::~Incrementp()
{

}

int				Incrementp::exec()
{
	(*this->_head)++;
	return IInstruction::OK;
	
}

Incrementp			&Incrementp::operator=(Incrementp const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
