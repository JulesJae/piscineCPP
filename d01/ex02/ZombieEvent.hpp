#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
	public:
		void 			setZombieType(std::string type);
		Zombie			*newZombie(std::string name) const;
		Zombie			*randomChump() const;
		ZombieEvent();

	private:
		std::string			_type;
		static char const	*_names[];
};

#endif