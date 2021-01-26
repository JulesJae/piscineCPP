#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &bot);
		~ScavTrap(); 

		ScavTrap			&operator=(ScavTrap const &rhs);

		void				challengeNewcomer(std::string const &target);

	private:
		static std::string	_challenges[];

};

#endif
