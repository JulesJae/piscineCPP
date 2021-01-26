#include "ZombieHorde.hpp"
#include <iostream>
#include <ctime>

char const *ZombieHorde::_names[] = { "Philidor", "Anand", "Karpov", "Kasparov", "Fischer", "Laskin", "Lasker", "Capablanca", "Alekhine" };

ZombieHorde::ZombieHorde(int n)
{
	int					i(0);
	int     			random;
    int     			size;

	this->_n = n;
	if (n < 0)
	{
		std::cout << "ZombieHorde: creation parameter must be a positive number\n";
		return;
	}
	try {
		this->_zombies = new Zombie[n];
		std::srand(std::time(nullptr));
    	size = sizeof(ZombieHorde::_names) / sizeof(char*);
		while (i < n)
		{
    		random = std::rand() % size;
			this->_zombies[i].name = ZombieHorde::_names[random];
			i++;
		}
	} catch (std::bad_alloc &e)
	{
		std::cout << " Exception bad Alloc catched\n";
	}
}

ZombieHorde::~ZombieHorde()
{
	if (this->_n > 0)
	{
		std::cout << "Bye bye my dear champs ...\n";
		delete[] this->_zombies;
	}
}

void ZombieHorde::announce() const
{
	int		i(0);

	while (i < this->_n)
	{
		this->_zombies[i].advert();
		i++;
	}
}
