#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>
#include <ctime>

int     main()
{
	NinjaTrap	konohamaru("Konohamaru");
	

	std::srand(std::time(nullptr));
	konohamaru.rangedAttack("Stan Marsh");
	konohamaru.meleeAttack("Gerdald Broflowski");
	konohamaru.beRepaired(3);;
	konohamaru.takeDamage(101);
	konohamaru.takeDamage(99);
	konohamaru.beRepaired(55);
	konohamaru.ninjaShoebox(NinjaTrap("Naruto"));
	konohamaru.ninjaShoebox(FragTrap("Krilin"));
	konohamaru.ninjaShoebox(ScavTrap("Yamcha"));
	konohamaru.ninjaShoebox(ClapTrap("Chao-Zu"));
}