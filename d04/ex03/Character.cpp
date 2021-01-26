#include "Character.hpp"
#include <iostream>

Character::Character(std::string const &name)
{
	this->_name = name;
	this->_freeSlots = NUMBER_OF_SLOTS;
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
		this->_materias[i] = nullptr;
	std::cout << name << " character constructed\n";
}

Character::Character(Character const &obj)
{
	*this = obj;
}

Character::~Character()
{
	std::cout << this->_name << " character destructed\n";
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
		if (this->_materias[i] != nullptr)
			delete this->_materias[i];
}
std::string const	&Character::getName() const { return this->_name; }
AMateria const		*Character::getMateria(int idx) const { return this->_materias[idx]; }

void				Character::equip(AMateria *m)
{
	if (!this->_freeSlots)
	{
		std::cout << this->_name << ": I have to unequip One materia first\n";
		return ;
	}
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
		if(this->_materias[i] == nullptr)
			{
				this->_materias[i] = m;
				break;
 			}
	this->_freeSlots--;
}

void				Character::unequip(int idx)
{
	std::cout << this->_name << " materia " << this->_materias[idx]->getType() << " unequiped\n";
	this->_materias[idx] = nullptr;
	this->_freeSlots++;
}

void				Character::use(int idx, ICharacter &target)
{
	std::cout << this->_name << ": ";
	this->_materias[idx]->use(target);
}

Character			&Character::operator=(Character const &rhs)
{
	std::cout << "OERATOR =\n";
	for (int i = 0; i < NUMBER_OF_SLOTS; i++)
	{
		if (this->_materias[i] != nullptr)
		{
			delete this->_materias[i];
			this->_materias[i] = nullptr;
		}
		if (rhs.getMateria(i) != nullptr)
		{
			std::cout << "CLONAGE: " << rhs.getMateria(i)->getType() << std::endl;
			this->_materias[i] = rhs.getMateria(i)->clone();
		}
	}
	return *this;
}
