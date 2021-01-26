#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

# define NUMBER_OF_SLOTS 4

class Character:public ICharacter
{
	public:
		Character(std::string const &name);
		Character(Character const &obj);
		virtual ~Character();

		Character			&operator=(Character const &rhs);

		std::string	const	&getName() const;
		AMateria const		*getMateria(int idx) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

		
	private:
		std::string			_name;
		AMateria			*_materias[NUMBER_OF_SLOTS];
		int					_freeSlots;
	
};

#endif