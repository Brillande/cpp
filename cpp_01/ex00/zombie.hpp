/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:26:46 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:26:47 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie 
{
    private:
        std:: string _name;
    public:
        Zombie(std::string name);
        ~Zombie(); 
        void announce (void) const; 
};
Zombie *newZombie(std::string name);
void randomChump(std::string name);

