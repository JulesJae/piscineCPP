#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>

Squad::Squad(): _count(0)
{
	std::cout << "Squad constructed\n";
}

Squad::Squad(Squad const &obj)
{
	*this = obj;
}

Squad::~Squad()
{
	std::cout << "Squad destructer\n";
	for (int i = 0; i <= this->_count; i++)
		delete this->_marines[i];
}

int				Squad::getCount() const { return this->_count; }

ISpaceMarine	*Squad::getUnit(int i) const { return this->_marines[i]; }

int				Squad::push(ISpaceMarine *marine)
{
	if (this->_count != MEMBERS - 1)
	{
		this->_marines[this->_count] = marine;
		this->_count++;
		std::cout << "NEW member in squad, count: " << this->_count << std::endl;
		return (1);
	}
	std::cout << "Squad full\n";
	return (0);
}

Squad			&Squad::operator=(Squad const &rhs)
{
	this->_count = rhs.getCount();
	for (int i = 0; i <= rhs.getCount(); i++)
	{
		delete this->_marines[i];
		this->_marines[i] = rhs.getUnit(i)->clone();
	}
	return *this;
}
