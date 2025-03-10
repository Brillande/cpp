/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:24:59 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:25:00 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

#include "HumanB.hpp"

HumanB::HumanB(string name) : _name(name)
{
    this->_isArmed = false;
	cout << this->_name <<" spawned" << endl;
}

HumanB::~HumanB()
{
    cout << this->_name << " died" << endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    this->_weapon = &Weapon;
    this->_isArmed = true;
    cout << this->_name << " take a " << this->_weapon->getType() << endl;
}

void HumanB::attack()
{
    if(this->_isArmed)
    {
        cout << "starts figthin with " << this->_weapon->getType() << endl;
    }
    else
    {
        cout << this->_name << " haven`t a weapon and starts running" << endl;
    }
}