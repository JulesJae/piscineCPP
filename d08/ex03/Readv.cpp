#include "Readv.hpp"
#include <iostream>

Readv::Readv(char **head): _head(head)
{
	this->_type = ',';
}

Readv::Readv(Readv const &obj)
{
	*this = obj;
}

Readv::~Readv()
{

}

int				Readv::exec()
{
	std::cin >> **this->_head;
	return IInstruction::OK;
}

Readv			&Readv::operator=(Readv const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
