/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:31:37 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/05 16:19:43 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using namespace std;

int main(void) {
	ScavTrap ugo("ugo");
	ScavTrap maialen(ugo);

	maialen.setName("maialen");
	ugo.attack(maialen.getName());
	maialen.guardGate();

	cout << endl;

	ScavTrap ohNo;
	ohNo = ugo;
	ugo.attack(maialen.getName());
	maialen.guardGate();

}
