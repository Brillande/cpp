using namespace std;

#include "zombie.hpp"

void randomChump(string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}