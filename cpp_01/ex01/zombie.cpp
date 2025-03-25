/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:57 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:03:13 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " is dead" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}

void	Zombie::setName(std::string name)
{
    _name = name;
}