#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

class ScavTrap
{
	public:
		std::string			name;
		unsigned int		hp;
		unsigned int		maxHp;
		unsigned int		mana;
		unsigned int		maxMana;
		unsigned int		lvl;
		unsigned int		meleeDamage;
		unsigned int		rangeDamage;
		unsigned int		armor;

		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &bot);
		~ScavTrap(); 

		ScavTrap			&operator=(ScavTrap const &rhs);

		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				challengeNewcomer(std::string const &target);

	private:
		ScavTrap();
		static std::string	_challenges[];

};

#endif
