#include <iostream>
#include "Human.hpp"

typedef void	(Human::* memberPtr)(std::string const&);

void Human::meleeAttack(std::string const& target)
{
	std::cout << "call friends to smash " << target << std::endl;
}

void Human::rangedAttack(std::string const& target)
{
	std::cout << "Take a bow and shoot " << target << std::endl;
}

void Human::intimidatingShout(std::string const& target)
{
	std::cout << "Yell like Lara Fabian on " << target << std::endl;
}

void Human::action(std::string const& action_name, std::string const& target)
{
	memberPtr	functions[] = {
		&Human::intimidatingShout,
		&Human::meleeAttack,
		&Human::rangedAttack
	};

	std::string	fn_names[] = {
		"intimidatingShout",
		"meleeAttack",
		"rangedAttack"
	};

	int		i(0);

	while (i < 3)
	{
		if (fn_names[i] == action_name)
		{
			(this->*functions[i])(target);
			break;
		}
		i++;
	}

}