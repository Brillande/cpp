/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:40 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:46:05 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "constructor Cat empty" << std::endl;
}

Cat::Cat(const Cat &src) : Animal("Cat") {
  if (this != &src)
    *this = src;
  std::cout << "constructor Cat copy" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "destructor Cat" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Miau maiu i'm the cat" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
