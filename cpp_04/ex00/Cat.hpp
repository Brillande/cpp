/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:20:41 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 19:05:30 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <iostream>


class Cat : public Animal {
public:
  Cat();
  Cat(const Cat &src);
  ~Cat();

  Cat &operator=(Cat const &src);

private:
    using Animal::operator=;
  void makeSound(void) const;
};
