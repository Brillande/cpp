/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:33:01 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/26 12:11:01 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std ::string &name) : ClapTrap(name) {
    std ::cout << "ScavTrap " << name << ": constructor called" << std ::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    std ::cout << "ScavTrap " << _name << ": constructor copy called" << std ::endl;
}

ScavTrap::ScavTrap(void) {
    std ::cout << "ScavTrap no name: constructor void called" << std ::endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap(void) {
    std ::cout << "ScavTrap " << _name << ": Destructor called" << std ::endl;
}

void ScavTrap::attack(const std ::string &target) {
    if (_health == 0) {
        std ::cout << "ScavTrap " << _name << "is dead" << std ::endl;
    } else if (_energyPoint == 0) {
        std ::cout << "ScavTrap " << _name << "hasn't no energy points" << std ::endl;
    } else {
        std ::cout << "ScavTrap " << _name << " attacks " << target
                  << " with " << _attackDamage << " points of damage!"
                  << std ::endl;
        _energyPoint--;
    }
}

void ScavTrap::guardGate() const {
    std ::cout << "ScavTrap " << _name << " is now in Gate keeper mode"
              << std ::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &value) {
	if (this != &value)
		ClapTrap::operator=(value);
	return (*this);
}
