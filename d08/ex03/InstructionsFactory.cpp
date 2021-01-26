#include "InstructionsFactory.hpp"
#include "Decrementp.hpp"
#include "Decrementv.hpp"
#include "Incrementv.hpp"
#include "Incrementp.hpp"
#include "Loopend.hpp"
#include "Loopstart.hpp"
#include "Readv.hpp"
#include "Writev.hpp"

InstructionsFactory::InstructionsFactory() 
{

}

InstructionsFactory::InstructionsFactory(InstructionsFactory const &obj)
{
	*this = obj;
}

InstructionsFactory::~InstructionsFactory()
{

}

IInstruction				*InstructionsFactory::create(char c, char **ptr)
{
	switch ( c )
	{
		case '>':
			return new Incrementp(ptr);
		case '<':
			return new Decrementp(ptr);
		case '+':
			return new Incrementv(ptr);
		case '-':
			return new Decrementv(ptr);
		case '[':
			return new Loopstart(ptr);
		case ']':
			return new Loopend(ptr);
		case '.':
			return new Writev(ptr);
		case ',':
			return new Readv(ptr);
		default:
			return nullptr;
	}
}

InstructionsFactory			&InstructionsFactory::operator=(InstructionsFactory const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}
