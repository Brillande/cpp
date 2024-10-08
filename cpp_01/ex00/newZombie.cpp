using namespace std;

#include "zombie.hpp"

Zombie *newZombie(string name)
{
   Zombie *manolo = new Zombie(name);
	manolo->announce();
	return (manolo);
}