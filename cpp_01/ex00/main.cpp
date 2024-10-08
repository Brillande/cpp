#include "zombie.hpp"

int main (void)
{
    Zombie *manolo = newZombie("manolo");
    randomChump("Miguel");
    delete manolo;
    return (0);
}