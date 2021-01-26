#include "FragTrap.hpp"
#include <string>
#include <iostream>
#include <ctime>

FragTrap::FragTrap(std::string name): name(name), hp(100), maxHp(100), mana(100), maxMana(100), lvl(1)
	, meleeDamage(30), rangeDamage(20), armor(5)
{
	std::cout << "FR4G-TP " << name << " has been constructed\n";
}

FragTrap::FragTrap(FragTrap const &bot)
{
	*this = bot;
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

void        FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << this->name << " shoot on " << target << ", damage: " << this->rangeDamage << std::endl;
}

void        FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "FR4G-TP " << this->name << " strike " << target << ", damage: " << this->meleeDamage << std::endl;
}

void        FragTrap::takeDamage(unsigned int amount)
{
	unsigned int    real_amount(amount - this->armor);

	if (real_amount <= this->hp)
	{
		this->hp -= real_amount;
		std::cout << "FR4G-TP " << this->name << " take " << real_amount << " damage, he has now " << this->hp << "HP\n";
	} else 
		std::cout << "FR4G-TP " << this->name << " HP can't be lesser than 0\n";
}

void        FragTrap::beRepaired(unsigned int amount)
{
	if (amount + this->hp <= this->maxHp)
	{
		this->hp += amount;
		std::cout << "FR4G-TP " << this->name << " be repaired by " << amount << " hp, he has now " << this->hp << "HP\n";
	} else 
		std::cout << "FR4G-TP " << this->name << " HP can't be greater than " << this->maxHp << std::endl;
}

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
