/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:31:55 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/05 16:19:54 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using namespace std;

ScavTrap::ScavTrap(const string &name) : ClapTrap(name) {
    cout << "ScavTrap " << name << ": constructor called" << endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    *this = other;
    cout << "ScavTrap " << _name << ": constructor copy called" << endl;
}

ScavTrap::ScavTrap(void) {
    cout << "ScavTrap no name: constructor void called" << endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap(void) {
    cout << "ScavTrap " << _name << ": Destructor called" << endl;
}

void ScavTrap::attack(const string &target) {
    if (_health == 0) {
        cout << "ScavTrap " << _name << "is dead" << endl;
    } else if (_energyPoint == 0) {
        cout << "ScavTrap " << _name << "hasn't no energy points" << endl;
    } else {
        cout << "ScavTrap " << _name << " attacks " << target
                  << " with " << _attackDamage << " points of damage!"
                  << endl;
        _energyPoint--;
    }
}

void ScavTrap::guardGate() const {
    cout << "ScavTrap " << _name << " is now in Gate keeper mode"
              << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &value) {
	if (this != &value)
		ClapTrap::operator=(value);
	return (*this);
}
