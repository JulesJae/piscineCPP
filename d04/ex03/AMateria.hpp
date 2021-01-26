#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "include.hpp"
# include "ICharacter.hpp"

class AMateria;

class AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &obj);
		virtual ~AMateria();

		AMateria			&operator=(AMateria const &rhs);

		std::string const	&getType() const;
		unsigned int		getXP() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
		
	private:
		std::string			_type;
		unsigned int		_xp;
	
};

#endif