#include "ScavTrap.hpp"
#include <string>
#include <iostream>
#include <ctime>

ScavTrap::ScavTrap(std::string name): name(name), hp(100), maxHp(100), mana(50), maxMana(50), lvl(1)
	, meleeDamage(20), rangeDamage(15), armor(3)
{
	std::cout << "SC4V-TP " << name << " has been constructed\n";
}

ScavTrap::ScavTrap(ScavTrap const &bot)
{
	std::cout << "SC4V-TP:  copy constructor called\n";
	*this = bot;
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

void        ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "SC4V-TP " << this->name << " shoot on " << target << ", damage: " << this->rangeDamage << std::endl;
}

void        ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "SC4V-TP " << this->name << " strike " << target << ", damage: " << this->meleeDamage << std::endl;
}

void        ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int    real_amount(amount - this->armor);

	if (real_amount <= this->hp)
	{
		this->hp -= real_amount;
		std::cout << "SC4V-TP " << this->name << " take " << real_amount << " damage, he has now " << this->hp << "HP\n";
	} else 
		std::cout << "SC4V-TP " << this->name << " HP can't be lesser than 0\n";
}

void        ScavTrap::beRepaired(unsigned int amount)
{
	if (amount + this->hp <= this->maxHp)
	{
		this->hp += amount;
		std::cout << "SC4V-TP " << this->name << " be repaired by " << amount << " hp, he has now " << this->hp << "HP\n";
	} else 
		std::cout << "SC4V-TP " << this->name << " HP can't be greater than " << this->maxHp << std::endl;
}

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
