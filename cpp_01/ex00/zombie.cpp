using namespace std;

#include "zombie.hpp"

Zombie::Zombie(string name) : _name(name)
{
	cout << "Zombie " << _name << " was born" << endl;
}

Zombie::~Zombie()
{
	cout << "zombie " << this->_name << " died.\n"  << endl;
}


void	Zombie::announce(void) const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ...\n" << endl;
}