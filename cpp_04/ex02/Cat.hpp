/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:54:15 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:26:25 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat : public AAnimal {
public:
  Cat();
  Cat(const Cat &src);
  ~Cat();

  void setBrainIdear(const std::string &idea, unsigned int offset);
  std::string getBrainIdear(unsigned int offset);

  Cat &operator=(Cat const &src);

private:
  void makeSound(void) const;
  using AAnimal::operator=;
  Brain *_brain;
};
