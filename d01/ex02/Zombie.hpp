#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		std::string		name;
		std::string		type;

		Zombie(std::string name, std::string type);
		~Zombie();
		void			advert(void) const;


};

#endif