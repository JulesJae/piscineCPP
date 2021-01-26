#include "FragTrap.hpp"
#include <string>
#include <iostream>
#include <ctime>

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->mana = 100;
	this->maxMana = 100;
	this->meleeDamage = 30;
	this->rangeDamage = 20;
	this->armor = 5;
	std::cout << "FR4G-TP " << name << " has been constructed\n";
}

FragTrap::FragTrap(FragTrap const &bot): ClapTrap(bot)
{
	std::cout << "FR4G-TP:  copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP " << this->name << " has been destroyed\n";
}

std::string			FragTrap::_attacks[] = {
	" Doing a Mawashi-Geri on ",
	" Doing 100 years of suffering on ",
	" Make a shampoo at ",
	" Doing an assassin tackle like Gatuso on ",
	" Fart in the nose on "
};

void        FragTrap::vaulthunder_dot_exe(std::string const &target)
{
	int         i;

	if (this->mana >= 25)
	{
		this->mana -= 25;
		i = std::rand() % 5;
		std::cout << "FR4G-TP " << this->name << FragTrap::_attacks[i] << target << std::endl;
	} else
		std::cout << "FR4G-TP " << this->name << " has not enough mana\n";
}

FragTrap    &FragTrap::operator=(FragTrap const &rhs)
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
