#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap: public virtual FragTrap, public virtual NinjaTrap
{
    public:
        SuperTrap(std::string const &name);
        SuperTrap(SuperTrap const &bot);
        ~SuperTrap();

        void			rangedAttack(std::string const &target) const;
		void			meleeAttack(std::string const &target) const;

        SuperTrap       &operator=(SuperTrap const &rhs);

    private:

};

#endif
