using namespace std;

#include "Weapon.hpp"

Weapon::Weapon(const string &type)
{
    this->setType(type);
}

Weapon::~Weapon()
{
    cout << "the weapon "<< getType() << " is broken" << endl;
}

string Weapon::getType () const
{
    return (_type);
}

void Weapon::setType(const string &type)
{
    this->_type = type;
}