#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	public:
		Character(std::string const &name);
		Character(Character const &obj);
		~Character();

		Character			&operator=(Character const &rhs);

		std::string			getName() const;
		int					getAP() const;
		AWeapon				*getWeapon() const;
		void				recoverAP();
		void				equip(AWeapon *weapon);
		void				attack(Enemy *enemy);
		
	private:
		Character();
		AWeapon				*_weapon;
		std::string			_name;
		int					_ap;
	
};

std::ostream				&operator<<(std::ostream &o, Character const &character);

#endif