#include "Character.hpp"
#include "Enemy.hpp"
#include <iostream>

Character::Character(std::string const &name): _weapon(nullptr), _name(name), _ap(40)
{
	std::cout << name << " is born and he is going to kick some ass !\n";
}

Character::Character(Character const &obj)
{
	*this = obj;
}

Character::~Character()
{
	std::cout << this->_name << " is dead, what a terrible destiny...\n";
}

std::string			Character::getName() const { return this->_name; }

void				Character::recoverAP() 
{
	int		recover(40 - this->_ap >= 10 ? 10 : 40 - this->_ap);

	this->_ap += recover;
	std::cout << recover << " ap recovered, total: " << this->_ap << std::endl;
}

void				Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
	std::cout << this->_name << ", " << weapon->getName() << " equiped\n";
}

void				Character::attack(Enemy *enemy)
{
	if (!this->_weapon)
		return;
	std::cout << this->_name << ", attack " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
	if (this->_ap >= this->_weapon->getAPCost())
	{
		this->_weapon->attack();
		enemy->getDamage(this->_weapon->getDamage());
		if (enemy->getHP() == 0)
		{
			delete enemy;
		}
	}
	else
		std::cout << "argg not enough AP\n";
	
}

int					Character::getAP() const { return this->_ap; }
AWeapon				*Character::getWeapon() const { return this->_weapon; }

Character			&Character::operator=(Character const &rhs)
{
	this->_name = rhs.getName();
	this->_weapon = rhs.getWeapon();
	this->_ap = rhs.getAP();
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Character const &c)
{
	o << c.getName() << " has " << c.getAP();
	if (c.getWeapon())
		o << " and carries a " << c.getWeapon()->getName() << std::endl;
	else 
		o << " and is unarmed\n";
	return o;
}
