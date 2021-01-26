#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int		main()
{
	Zombie		stack("Stack", "virgin");
	Zombie		*zombie;
	ZombieEvent	ze;

	stack.advert();
	zombie = ze.newZombie("Chipster");
	zombie->advert();
	delete zombie;
	ze.setZombieType("Hangover");
	zombie = ze.randomChump();
	delete zombie;
}