using namespace std;

#include "zombie.hpp"

Zombie *zombieHorde(int N, string name)
{
    if(N <= 0)
        return (NULL);
    Zombie *horde = new Zombie[N];
    if(horde == NULL)
        return (NULL);
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
        horde[i].announce();
    }
    return (horde);
}