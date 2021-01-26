#include "Loopstart.hpp"
#include <iostream>

Loopstart::Loopstart(char **head): _head(head)
{
	this->_type = '[';
}

Loopstart::Loopstart(Loopstart const &obj)
{
	*this = obj;
}

Loopstart::~Loopstart()
{

}

int				Loopstart::exec()
{
	if (!(**this->_head))
		return IInstruction::ADVANCE;
	return IInstruction::OK;
}

Loopstart			&Loopstart::operator=(Loopstart const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
