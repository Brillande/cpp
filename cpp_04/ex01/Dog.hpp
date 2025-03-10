/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:54:16 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:06:06 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(const Dog &src);
  ~Dog();

  void setBrainIdear(const std::string &idea, unsigned int offset);
  std::string getBrainIdear(unsigned int offset);

  Dog &operator=(Dog const &src);

private:
  void makeSound(void) const;

  Brain *_brain;
};
