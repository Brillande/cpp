/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:07 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:09 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
class Zombie 
{
    private:
        std:: string _name;
    public:
        Zombie();
        ~Zombie(); 
        void announce (void) const;
        void setName(std::string name);
};
Zombie *zombieHorde(int N, std::string name);


#endif