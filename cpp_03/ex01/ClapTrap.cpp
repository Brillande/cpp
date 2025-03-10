/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:33:19 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/05 16:19:32 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using namespace std;

ClapTrap::ClapTrap(const string &name)
    : _name(name),
      _energyPoint(10),
      _attackDamage(0),
      _health(10) {
    cout << "ClapTrap " << name << " constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    *this = other;
    cout << "ClapTrap " << _name << " constructor copy called"
              << endl;
}

ClapTrap::ClapTrap(void) : _energyPoint(10), _attackDamage(0), _health(10) {
    cout << "ClapTrap no name constructor called" << endl;
}

ClapTrap::~ClapTrap(void) {
    cout << "ClapTrap " << _name << " destructor called" << endl;
}

void ClapTrap::attack(const string &target) {
    if (_health == 0) {
        cout << "ClapTrap " << _name
                  << " has dead" << endl;
    } else if (_energyPoint == 0) {
        cout << "ClapTrap " << _name
                  << ": hasen't energy points left" << endl;
    } else {
        cout << "ClapTrap " << _name << " attacks " << target
                  << ", with " << _attackDamage << " points of damage!"
                  << endl;
        _energyPoint--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    cout << "ClapTrap " << _name << " gets attacked and recibe " << amount
              << " damage!" << endl;
    if (_health > amount) {
        _health -= amount;
    } else {
        _health = 0;
        cout << "ClapTrap " << _name << " has died"
                  << endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_health == 0) {
        cout << "ClapTrap " << _name
                  << ": is dead" << endl;
    } else if (_energyPoint == 0) {
        cout << "ClapTrap " << _name
                  << "has no energy" << endl;
    } else {
        cout << "ClapTrap " << _name << " is repaired wining " << amount
                  << " health points!" << endl;
        _health += amount;
    }
}

void ClapTrap::setName(const string &value) { _name = value; }
void ClapTrap::setHealth(const unsigned int &value) {
    _health = value;
    cout << "ClapTrap " << _name << " up health to " << value
              << endl;
}
void ClapTrap::setEnergyPoint(const unsigned int &value) {
    _energyPoint = value;
}
void ClapTrap::setAttackDamage(const unsigned &value) {
    cout << "ClapTrap " << _name << " up attack damage to " << value
              << endl;
    _attackDamage = value;
}

string  ClapTrap::getName(void) const { return _name; }
unsigned int ClapTrap::getHealth(void) const { return _health; }
unsigned int ClapTrap::getEnergyPoint(void) const { return _energyPoint; }
unsigned int ClapTrap::getAttackDamage(void) const { return _attackDamage; }

ClapTrap &ClapTrap::operator=(const ClapTrap &value) {
	if (this == &value)
        return *this;
	this->_name = value._name;
	this->_energyPoint = value._energyPoint;
	this->_attackDamage = value._attackDamage;
	this->_health = value._health ;
	return (*this);
}
