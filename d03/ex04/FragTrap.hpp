#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const &bot);
		FragTrap();
		~FragTrap(); 

		FragTrap			&operator=(FragTrap const &rhs);

		void				vaulthunder_dot_exe(std::string const &target);

	private:
		static std::string	_attacks[];

};

#endif
