#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include <ctime>

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->mana = 50;
	this->maxMana = 50;
	this->meleeDamage = 20;
	this->rangeDamage = 15;
	this->armor = 3;
	std::cout << "SC4V-TP " << name << " has been constructed\n";
}

ScavTrap::ScavTrap(ScavTrap const &bot): ClapTrap(bot)
{
	std::cout << "SC4V-TP:  copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP " << this->name << " has been destroyed\n";
}

std::string			ScavTrap::_challenges[] = {
	"If there are four sheep, two dogs and one herds-men, how many feet are there? ",
	"Touch your elbow with your tongue",
	"Count to 100",
	"Do a backflip",
	"Do an octogone with Booba"
};

void        ScavTrap::challengeNewcomer(std::string const &target)
{
	int         i;

	this->mana -= 25;
	i = std::rand() % 5;
	std::cout << "Hey " << target << "! it's time to SC4V-TP Challenge: " << ScavTrap::_challenges[i] << std::endl;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &rhs)
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
