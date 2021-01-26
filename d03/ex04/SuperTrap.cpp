#include "SuperTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>
#include <iostream>

SuperTrap::SuperTrap(std::string const &name): ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5)
{
	std::cout << "SUP3R-TP " << name << " has been constructed\n";
}

SuperTrap::SuperTrap(SuperTrap const &bot): ClapTrap(bot)
{
	std::cout << "SUP3R-TP " << name << " has been constructed\n";
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUP3R-TP " << this->name << " has been destroyed\n";
}

void		SuperTrap::rangedAttack(std::string const &target) const
{
	FragTrap::rangedAttack(target);
}

void		SuperTrap::meleeAttack(std::string const &target) const
{
	NinjaTrap::meleeAttack(target);
}

SuperTrap    &SuperTrap::operator=(SuperTrap const &rhs)
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