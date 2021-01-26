#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string const &name): name(name), hp(100), maxHp(100), mana(0), maxMana(0), lvl(1)
	, meleeDamage(0), rangeDamage(0), armor(0)
{
	std::cout << "CL4P-TP " << name << " has been constructed\n";
}

ClapTrap::ClapTrap(ClapTrap const &bot)
{
	std::cout << "CL4P-TP:  copy constructor called\n";
	*this = bot;
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP " << this->name << " has been destroyed\n";
}

void        ClapTrap::rangedAttack(std::string const &target) const
{
	std::cout << "CL4P-TP " << this->name << " shoot on " << target << ", damage: " << this->rangeDamage << std::endl;
}

void        ClapTrap::meleeAttack(std::string const &target) const
{
	std::cout << "CL4P-TP " << this->name << " strike " << target << ", damage: " << this->meleeDamage << std::endl;
}


void        ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int    real_amount(amount - this->armor);

	if (real_amount <= this->hp)
	{
		this->hp -= real_amount;
		std::cout << "CL4P-TP " << this->name << " take " << real_amount << " damage, he has now " << this->hp << "HP\n";
	} else 
		std::cout << "CL4P-TP " << this->name << " HP can't be lesser than 0\n";
}

void        ClapTrap::beRepaired(unsigned int amount)
{
	if (amount + this->hp <= this->maxHp)
	{
		this->hp += amount;
		std::cout << "CL4P-TP " << this->name << " be repaired by " << amount << " hp, he has now " << this->hp << "HP\n";
	} else 
		std::cout << "CL4P-TP " << this->name << " HP can't be greater than " << this->maxHp << std::endl;
}


ClapTrap    &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->name = rhs.name;
	this->hp = rhs.hp;
	this->maxHp = rhs.maxHp;
	this->mana = rhs.mana;
	this->maxMana = rhs.maxMana;
	this->lvl = rhs.lvl;
	this->meleeDamage = rhs.meleeDamage;
	this->rangeDamage = rhs.rangeDamage;
	this->armor = rhs.armor;
	return *this;
}
