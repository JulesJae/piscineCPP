#include "Writev.hpp"
#include <iostream>

Writev::Writev(char **head): _head(head)
{
	this->_type = '.';
}

Writev::Writev(Writev const &obj)
{
	*this = obj;
}

Writev::~Writev()
{

}

int				Writev::exec()
{
	// std::cout << "WRITE BRO head = " << static_cast<int>(**this->_head) << " vl\n";
	std::cout << **this->_head;
	return IInstruction::OK;
}

Writev			&Writev::operator=(Writev const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
