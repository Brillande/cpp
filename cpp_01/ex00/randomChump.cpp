/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:32 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:33 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

#include "zombie.hpp"

void randomChump(string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}