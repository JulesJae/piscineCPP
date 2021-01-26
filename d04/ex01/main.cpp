#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRiffle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include <iostream>

int     main()
{
    Character   hero("deadpool");
    PlasmaRiffle    pr;
    PowerFist       pf;
    bool            stop(false);
    RadScorpion     *rs(new RadScorpion());
    SuperMutant     *sm(new SuperMutant());

    std::cout << hero;
    hero.equip(&pr);
    std::cout << "\n\n starting kick RadScorpion's ass\n\n";
    while (!stop)
    {
        if (rs->getHP() <= hero.getWeapon()->getDamage())
            stop = true;
        if (hero.getAP() < hero.getWeapon()->getAPCost())
            hero.recoverAP();
        hero.attack(rs);
    }
    stop = false;
    hero.equip(&pf);
    std::cout << "\n\n starting kick SuperMutant's ass\n\n";
    while (!stop)
    {
        if (sm->getHP() <= hero.getWeapon()->getDamage())
            stop = true;
        if (hero.getAP() < hero.getWeapon()->getAPCost())
            hero.recoverAP();
        hero.attack(sm);
    }
    std::cout << "\n\n";
    return 0;
}