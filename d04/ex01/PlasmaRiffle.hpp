#ifndef PLASMARIFFLE_HPP
# define PLASMARIFFLE_HPP

# include <string>
# include "AWeapon.hpp"

class PlasmaRiffle: public AWeapon
{
	public:
		PlasmaRiffle();
		PlasmaRiffle(PlasmaRiffle const &obj);
		virtual ~PlasmaRiffle();

		PlasmaRiffle			&operator=(PlasmaRiffle const &rhs);

		void					attack()const;
		
	private:
	
};

#endif