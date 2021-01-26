#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <string>

class HumanA
{
    public:
        HumanA(std::string name);
        HumanA(std::string name, Weapon &weapon);
        void        attack();
        void        setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon      *_weapon;
};

#endif
