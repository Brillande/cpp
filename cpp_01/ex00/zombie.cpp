/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:37 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:00:22 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << _name << " was born" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "zombie " << this->_name << " died.\n"  << std::endl;
}


void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n" << std::endl;
}