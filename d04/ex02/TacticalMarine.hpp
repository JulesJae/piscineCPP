#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <string>
# include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const &obj);
		virtual ~TacticalMarine();

		TacticalMarine			&operator=(TacticalMarine const &rhs);

		virtual ISpaceMarine	*clone() const;
		virtual void			battleCry() const;
		virtual void			rangedAttack() const;
		virtual void			meleeAttack() const;

		
	private:
	
};

#endif