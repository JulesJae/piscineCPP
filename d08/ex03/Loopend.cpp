#include "Loopend.hpp"

Loopend::Loopend(char **head): _head(head)
{
	this->_type = ']';
}

Loopend::Loopend(Loopend const &obj)
{
	*this = obj;
}

Loopend::~Loopend()
{

}

int				Loopend::exec()
{
	if (!(**this->_head))
		return IInstruction::OK;
	return IInstruction::REWIND;
}

Loopend			&Loopend::operator=(Loopend const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
