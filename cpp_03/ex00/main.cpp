#include "ClapTrap.hpp"

using namespace std;

int main(void) {
    cout << "the fight of the century is about to begin, in the red corner "
                 "we have Ugo, and in the blue corner we have Maialen" << endl
              << "they start the figth" << endl;

    ClapTrap nb1("Ugo");
    ClapTrap nb2("Maialen");
    cout << endl;

    nb1.setAttackDamage(4);
    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.setAttackDamage(4);
    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());

    nb2.setAttackDamage(698);
    cout << nb2.getName()
              << " JUST UPGRADED HIS POWER TO THE SPEED OF LIGHT!!!" << endl;
    cout << "oh my lord " << nb1.getName() << " can survive?" << endl;
    nb1.beRepaired(10000);
    cout << "what is going on" << endl
              << "it can be" << endl
              << "a..." << endl
              << "comeback" << endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());

    cout << "amazing its a miracle" << endl
              << "WOW " << nb2.getName()
              << " CAN'T KILL " << nb1.getName() << endl;
    nb2.beRepaired(1999);
    cout << "I CANT UNDERSTAND WHAT IS HAPPENNING "
              << nb2.getName() << " ITS JUST HEALING HIMSELF" << endl
              << "AMAZING A COUNTER ATTACK " << nb1.getName()
              << " WOW " << nb1.getAttackDamage() << " ATTACK DAMAGE" << endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());
    nb1.setAttackDamage(6800);
    cout << nb1.getName()
              << " JUST UPGRADED HIS POWER TO THE SPEED OF SOUND!!!" << endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    cout << nb2.getName() << " IS DEAD" << endl
    <<nb1.getName() << " WINS !!!!!" << endl;
    return 0;
}
