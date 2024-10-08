using namespace std;

#include "zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    cout << "Zombie " << this->_name << " is dead" << endl;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}

void	Zombie::setName(string name)
{
    _name = name;
}