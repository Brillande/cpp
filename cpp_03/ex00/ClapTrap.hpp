/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:47:58 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/04 20:44:54 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <ostream>

class ClapTrap {
  public:
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap(void);
    ~ClapTrap(void);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void setName(const std::string &value);
    void setHealth(const unsigned int &value);
    void setEnergyPoint(const unsigned int &value);
    void setAttackDamage(const unsigned int &value);

    std::string  getName(void) const;
    unsigned int getHealth(void) const;
    unsigned int getEnergyPoint(void) const;
    unsigned int getAttackDamage(void) const;

    ClapTrap &operator=(const ClapTrap &);

  private:
    std::string  _name;
    unsigned int _energyPoint;
	unsigned int _attackDamage;
	unsigned int _health;
};
