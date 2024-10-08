using namespace std;

#include "zombie.hpp"

int main (void)
{
    Zombie *horde;
        
    horde = zombieHorde(42, "ellande");
    if(horde == NULL)
        return (1);
  delete[] horde;
    return (0);
}