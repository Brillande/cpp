using namespace std;

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(string name, Weapon &weapon) : _name(name) , _weapon(weapon)
{
	cout << this->_name <<" spawned and grabbed a " << this->_weapon.getType() << endl;
}

HumanA::~HumanA()
{
    cout << this->_name << " died" << endl;
}

void HumanA::attack()
{

    cout << "starts figthin with " << this->_weapon.getType() << endl;
}