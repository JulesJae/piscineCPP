#include "SuperTrap.hpp"
#include <iostream>
#include <ctime>

int     main()
{
	SuperTrap bowser("Bowser");

	std::cout << "Life of Bowser is " << bowser.hp << " mana is " << bowser.mana << std::endl;
	bowser.rangedAttack("Luigi");
	bowser.meleeAttack("Mario");
	bowser.ninjaShoebox(NinjaTrap("Sasuke"));
	bowser.ninjaShoebox(FragTrap("Eric Cartman"));
	bowser.ninjaShoebox(ScavTrap("Linus Torvald"));
	bowser.ninjaShoebox(ClapTrap("Bjarn Strousup"));
	for (int i = 0; i < 5; i++)
		bowser.vaulthunder_dot_exe("C++ Language");
	return 0;
}