#include <string>
#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int     main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* moi = new Character("moi");
    AMateria* tmp;
    
    tmp = src->createMateria("ice");
    moi->equip(tmp);
    tmp = src->createMateria("cure");
    moi->equip(tmp);
    ICharacter* bob = new Character("bob");
    moi->use(0, *bob);
    moi->use(1, *bob);

    bob->equip(tmp);
    bob->use(0, *bob);
    std::cout << tmp->getType() << ": has now " << tmp->getXP() << "XP\n";
    bob->unequip(0);

    std::cout << "\n Destruction \n\n";
    delete bob;
    delete moi;
    delete src;
}