/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:32:43 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/05 16:20:21 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using namespace std;

FragTrap::FragTrap(const string &name) : ClapTrap(name) {
    cout << "FragTrap " << name << ": constructor called" << endl;
    _health = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    *this = other;
    cout << "FragTrap " << _name << ": constructor copy called" << endl;
}

FragTrap::FragTrap(void) {
    cout << "FragTrap no name: constructor void called" << endl;
    _health = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

FragTrap::~FragTrap(void) {
    cout << "FragTrap " << _name << ": Destructor called" << endl;
}

void FragTrap::highFivesGuys(void) {
    cout << "FragTrap " << _name << ": high fives" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &value) {
	if (this != &value)
		ClapTrap::operator=(value);
	return (*this);
}
