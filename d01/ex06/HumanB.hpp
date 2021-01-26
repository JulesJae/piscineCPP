#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <string>

class HumanB
{
    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon &weapon);
        void        attack();
        void        setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon      *_weapon;
};

#endif
