#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{
	public:
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &bot);
		~NinjaTrap();

		NinjaTrap			&operator=(NinjaTrap const &rhs);

		void				ninjaShoebox(NinjaTrap const &target);
		void				ninjaShoebox(FragTrap const &target);
		void				ninjaShoebox(ScavTrap const &target);
		void				ninjaShoebox(ClapTrap const &target);

	private:
		NinjaTrap();

};

#endif
