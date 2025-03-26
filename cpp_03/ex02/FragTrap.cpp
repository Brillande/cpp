/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:32:43 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/26 12:10:50 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std ::string &name) : ClapTrap(name) {
    std ::cout << "FragTrap " << name << ": constructor called" << std ::endl;
    _health = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    std ::cout << "FragTrap " << _name << ": constructor copy called" << std ::endl;
}

FragTrap::FragTrap(void) {
    std ::cout << "FragTrap no name: constructor void called" << std ::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

FragTrap::~FragTrap(void) {
    std ::cout << "FragTrap " << _name << ": Destructor called" << std ::endl;
}

void FragTrap::highFivesGuys(void) {
    std ::cout << "FragTrap " << _name << ": high fives" << std ::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &value) {
	if (this != &value)
		ClapTrap::operator=(value);
	return (*this);
}
