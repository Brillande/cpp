/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:28 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:25:29 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(const std::string &type);
        ~Weapon();
        std::string getType () const;
        void setType(const std::string &type);
};

#endif