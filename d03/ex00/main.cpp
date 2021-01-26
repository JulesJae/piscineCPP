#include "FragTrap.hpp"
#include <iostream>
#include <ctime>

int     main()
{
	FragTrap		bot1("Eric Cartman");

	std::srand(std::time(nullptr));
	bot1.rangedAttack("Stan Marsh");
	bot1.meleeAttack("Gerdald Broflowski");
	bot1.beRepaired(3);;
	bot1.takeDamage(101);
	bot1.takeDamage(99);
	bot1.beRepaired(55);
	for (int i = 0; i < 5 ; i++)
		bot1.vaulthunder_dot_exe("Wendy Testaburger");
}