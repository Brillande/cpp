/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:14 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:25:15 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int main(void)
{
    Weapon sword("Sword");
    HumanA ellande("Ellande", sword);
    ellande.attack(); 

    Weapon axe("Axe");
    HumanB Maialen("Maialen");
    Maialen.attack(); 
    Maialen.setWeapon(axe);
    Maialen.attack();

    return 0;
}