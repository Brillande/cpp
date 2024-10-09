#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int main(void)
{
    Weapon sword("Sword");
    HumanA ellande("Ellande", sword);
    ellande.attack(); 

    Weapon axe("Axe");
    HumanB Maialen("Maialen");
    Maialen.attack(); 
    Maialen.setWeapon(axe);
    Maialen.attack();

    return 0;
}