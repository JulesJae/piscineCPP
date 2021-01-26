#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>

class FragTrap
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

		FragTrap(std::string name);
		FragTrap(FragTrap const &bot);
		~FragTrap(); 

		FragTrap			&operator=(FragTrap const &rhs);

		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		void				vaulthunder_dot_exe(std::string const &target);

	private:
		FragTrap();
		static std::string	_attacks[];

};

#endif
