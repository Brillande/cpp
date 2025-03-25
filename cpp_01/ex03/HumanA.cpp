/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:24:47 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:07:35 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name) , _weapon(weapon)
{
	std::cout << this->_name <<" spawned and grabbed a " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
    std::cout << this->_name << " died" << std::endl;
}

void HumanA::attack()
{

    std::cout << "starts figthin with " << this->_weapon.getType() << std::endl;
}