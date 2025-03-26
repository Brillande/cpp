#include "ClapTrap.hpp"

using namespace std;

int main(void) {
    std ::cout << "the fight of the century is about to begin, in the red corner "
                 "we have Ugo, and in the blue corner we have Maialen" << std ::endl
              << "they start the figth" << std ::endl;

    ClapTrap nb1("Ugo");
    ClapTrap nb2("Maialen");
    std ::cout << std ::endl;

    nb1.setAttackDamage(4);
    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.setAttackDamage(4);
    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());

    nb2.setAttackDamage(698);
    std ::cout << nb2.getName()
              << " JUST UPGRADED HIS POWER TO THE SPEED OF LIGHT!!!" << std ::endl;
    std ::cout << "oh my lord " << nb1.getName() << " can survive?" << std ::endl;
    nb1.beRepaired(10000);
    std ::cout << "what is going on" << std ::endl
              << "it can be" << std ::endl
              << "a..." << std ::endl
              << "comeback" << std ::endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());

    std ::cout << "amazing its a miracle" << std ::endl
              << "WOW " << nb2.getName()
              << " CAN'T KILL " << nb1.getName() << std ::endl;
    nb2.beRepaired(1999);
    std ::cout << "I CANT UNDERSTAND WHAT IS HAPPENNING "
              << nb2.getName() << " ITS JUST HEALING HIMSELF" << std ::endl
              << "AMAZING A COUNTER ATTACK " << nb1.getName()
              << " WOW " << nb1.getAttackDamage() << " ATTACK DAMAGE" << std ::endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());
    nb1.setAttackDamage(6800);
    std ::cout << nb1.getName()
              << " JUST UPGRADED HIS POWER TO THE SPEED OF SOUND!!!" << std ::endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    std ::cout << nb2.getName() << " IS DEAD" << std ::endl
    <<nb1.getName() << " WINS !!!!!" << std ::endl;
    return 0;
}
