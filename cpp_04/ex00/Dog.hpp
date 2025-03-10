/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:20:27 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 19:06:55 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>
class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &src);
  ~Dog();

  Dog &operator=(Dog const &src);

private:
    using Animal::operator=;
  void makeSound(void) const;
};
