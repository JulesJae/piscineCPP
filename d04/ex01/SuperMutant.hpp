#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <string>
# include "Enemy.hpp"

class SuperMutant: public Enemy
{
	public:
		SuperMutant();
		SuperMutant(SuperMutant const &obj);
		virtual ~SuperMutant();

		SuperMutant			&operator=(SuperMutant const &rhs);

		virtual void	getDamage(int damage);
		
	private:
	
};

#endif