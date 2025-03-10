/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:32:51 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/05 16:20:42 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
	FragTrap ugo("ugo");
	FragTrap maialen(ugo);

	maialen.setName("maialen");
	ugo.attack(maialen.getName());
	ugo.highFivesGuys();

}
