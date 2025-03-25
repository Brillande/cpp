/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:19 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:07:23 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
    this->setType(type);
}

Weapon::~Weapon()
{
    std::cout << "the weapon "<< getType() << " is broken" << std::endl;
}

std::string Weapon::getType () const
{
    return (_type);
}

void Weapon::setType(const std::string &type)
{
    this->_type = type;
}