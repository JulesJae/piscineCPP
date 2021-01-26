#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

# define MEMBERS 20

class Squad: public ISquad
{
	public:
		Squad();
		Squad(Squad const &obj);
		~Squad();

		Squad			&operator=(Squad const &rhs);

		int				getCount() const;
		ISpaceMarine	*getUnit(int i) const;
		int				push(ISpaceMarine *marine);
		
	private:
		ISpaceMarine	*_marines[MEMBERS];
		int				_count;
	
};

#endif