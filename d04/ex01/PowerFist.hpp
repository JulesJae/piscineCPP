#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <string>
# include "AWeapon.hpp"

class PowerFist: public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const &obj);
		virtual ~PowerFist();

		PowerFist			&operator=(PowerFist const &rhs);

		void					attack()const;
		
	private:
	
};

#endif