#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <string>
# include "Enemy.hpp"

class RadScorpion: public Enemy
{
	public:
		RadScorpion();
		RadScorpion(RadScorpion const &obj);
		virtual ~RadScorpion();

		RadScorpion			&operator=(RadScorpion const &rhs);

	private:
	
};

#endif