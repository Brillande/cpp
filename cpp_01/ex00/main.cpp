/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:20 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:21 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main (void)
{
    Zombie *manolo = newZombie("manolo");
    randomChump("Miguel");
    delete manolo;
    return (0);
}