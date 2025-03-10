/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:26 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:27 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

#include "zombie.hpp"

Zombie *newZombie(string name)
{
   Zombie *manolo = new Zombie(name);
	manolo->announce();
	return (manolo);
}