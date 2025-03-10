/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:53:52 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:02:40 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &src);
  ~Cat();

  void setBrainIdear(const std::string &idea, unsigned int offset);
  std::string getBrainIdear(unsigned int offset);

  Cat &operator=(Cat const &src);

private:
  void makeSound(void) const;

  Brain *_brain;
};
