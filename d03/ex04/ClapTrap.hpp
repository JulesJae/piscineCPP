#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
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

		ClapTrap(std::string const &name);
		ClapTrap(std::string name, unsigned int hp, unsigned int maxHp, unsigned int mana, unsigned int maxMana
			, unsigned int lvl, unsigned int meleeDamage, unsigned int rangeDamage, unsigned int armor);
		ClapTrap(ClapTrap const &bot);
		~ClapTrap();

		ClapTrap			&operator=(ClapTrap const &rhs);

		void				rangedAttack(std::string const &target) const;
		void				meleeAttack(std::string const &target) const;
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

	private:

};

#endif
