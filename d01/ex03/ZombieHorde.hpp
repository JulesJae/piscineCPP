#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int n);
		~ZombieHorde();
		void				announce() const;


	private:
		Zombie				*_zombies;
		int					_n;
		static char const	*_names[];
};

#endif