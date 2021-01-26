#include "Enemy.hpp"
#include <iostream>

Enemy::Enemy(int hp, std::string const &type): hp(hp), _type(type)
{
	std::cout << type << " Ennemy has been constructed\n";

}

Enemy::Enemy(Enemy const &obj)
{
	*this = obj;
}

Enemy::~Enemy()
{
	std::cout << this->_type << " Ennemy has been destructed\n";
}

void			Enemy::getDamage(int damage)
{
	if (damage < 0)
		return ;
		this->hp -= damage;
		if (this->hp < 0)
		{
			damage = this->hp * -1;
			this->hp = 0;
		}
		std::cout << "Ennemy: " << this->_type << ", damages: " << damage << ", actual hp: " << this->hp << std::endl;
}

std::string		Enemy::getType() const { return this->_type; }
int				Enemy::getHP() const { return this->hp; }

Enemy			&Enemy::operator=(Enemy const &rhs)
{
	this->_type = rhs.getType();
	this->hp = rhs.getHP();
	return *this;
}
