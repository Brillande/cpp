/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:49 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:25:50 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

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