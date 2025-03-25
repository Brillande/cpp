/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:12 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:05:27 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if(N <= 0)
        return (NULL);
    Zombie *horde = new Zombie[N];
    if(horde == NULL)
        return (NULL);
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
        horde[i].announce();
    }
    return (horde);
}