#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <string>
# include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
	public:
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const &obj);
		virtual ~AssaultTerminator();

		AssaultTerminator			&operator=(AssaultTerminator const &rhs);

		ISpaceMarine				*clone() const;
		void						battleCry() const;
		void						rangedAttack() const;
		void						meleeAttack() const;

		
	private:
	
};

#endif