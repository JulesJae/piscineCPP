#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		Ice(Ice const &obj);
		virtual ~Ice();

		Ice				&operator=(Ice const &rhs);

		virtual AMateria	*clone() const;
		
		virtual void	use(ICharacter &target);

		
	private:
	
};

#endif