#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <ctime>

int     main()
{
	FragTrap		bot1("Eric Cartman");
	ScavTrap		scav1("Mister Garisson");
	ScavTrap		scav2(scav1);
	

	std::srand(std::time(nullptr));
	bot1.rangedAttack("Stan Marsh");
	bot1.meleeAttack("Gerdald Broflowski");
	bot1.beRepaired(3);;
	bot1.takeDamage(101);
	bot1.takeDamage(99);
	bot1.beRepaired(55);
	for (int i = 0; i < 5 ; i++)
		bot1.vaulthunder_dot_exe("Wendy Testaburger");
	scav2.rangedAttack("Stan Marsh");
	scav2.meleeAttack("Gerdald Broflowski");
	scav2.beRepaired(3);;
	scav2.takeDamage(101);
	scav2.takeDamage(99);
	scav2.beRepaired(55);
	for (int i = 0; i < 5; i++)
		scav2.challengeNewcomer("Mister Slave");
}