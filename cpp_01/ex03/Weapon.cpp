/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:19 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:25:20 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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