/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:24:59 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:07:31 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
    this->_isArmed = false;
	std::cout << this->_name <<" spawned" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << this->_name << " died" << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    this->_weapon = &Weapon;
    this->_isArmed = true;
    std::cout << this->_name << " take a " << this->_weapon->getType() << std::endl;
}

void HumanB::attack()
{
    if(this->_isArmed)
    {
        std::cout << "starts figthin with " << this->_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->_name << " haven`t a weapon and starts running" << std::endl;
    }
}