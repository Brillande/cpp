/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:37 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:39 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

using namespace std;

#include "zombie.hpp"

Zombie::Zombie(string name) : _name(name)
{
	cout << "Zombie " << _name << " was born" << endl;
}

Zombie::~Zombie()
{
	cout << "zombie " << this->_name << " died.\n"  << endl;
}


void	Zombie::announce(void) const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ...\n" << endl;
}