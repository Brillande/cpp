/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:22 by babonnet          #+#    #+#             */
/*   Updated: 2025/03/04 20:39:38 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
  public:
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap(void);
    ~FragTrap(void);
	
    FragTrap &operator=(const FragTrap &);

    void highFivesGuys(void);
};
