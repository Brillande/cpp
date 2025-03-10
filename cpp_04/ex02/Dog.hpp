/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:54:49 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 19:11:15 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal {
public:
  Dog();
  Dog(const Dog &src);
  ~Dog();

  void setBrainIdear(const std::string &idea, unsigned int offset);
  std::string getBrainIdear(unsigned int offset);

  Dog &operator=(Dog const &src);

private:
  void makeSound(void) const;
  using AAnimal::operator=;
  Brain *_brain;
};
