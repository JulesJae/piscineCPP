#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(std::string const &name): ClapTrap(name)
{
    this->hp = 60;
    this->maxHp = 60;
	this->mana = 120;
	this->maxMana = 120;
	this->meleeDamage = 60;
	this->rangeDamage = 5;
	std::cout << "NINJ4-TP " << name << " has been constructed\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const &bot): ClapTrap(bot)
{
	std::cout << "NINJ4-TP:  copy constructor called\n";
}

NinjaTrap::NinjaTrap(): ClapTrap("OHOUI")
{
	std::cout << "NINJ4-TP " << name << " has been constructed\n";
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NINJ4-TP " << this->name << " has been destroyed\n";
}

void        NinjaTrap::ninjaShoebox(NinjaTrap const &target)
{
    std::cout << "NINJ4-TP " << this->name << " check " << target.name << " like a bro\n";
}

void        NinjaTrap::ninjaShoebox(FragTrap const &target)
{
    std::cout << "NINJ4-TP " << this->name << " use Konoha Goriki Senpu on " << target.name << std::endl;
}

void        NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
    std::cout << "NINJ4-TP " << this->name << " use Katon Goukyaku No Jutsu on " << target.name << std::endl;
}

void        NinjaTrap::ninjaShoebox(ClapTrap const &target)
{
    std::cout << "NINJ4-TP " << this->name << " use Kage Bushin No Jutsu on " << target.name << std::endl;
}

NinjaTrap    &NinjaTrap::operator=(NinjaTrap const &rhs)
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