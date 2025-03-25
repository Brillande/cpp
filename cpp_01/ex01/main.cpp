/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:49 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:01:18 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main (void)
{
    Zombie *horde;
        
    horde = zombieHorde(42, "ellande");
    if(horde == NULL)
        return (1);
  delete[] horde;
    return (0);
}