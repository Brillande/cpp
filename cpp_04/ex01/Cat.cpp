/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:53:08 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:47:15 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
  std::cout << "constructor Cat empty" << std::endl;
  _brain = new Brain;
}

Cat::Cat(const Cat &src) : Animal("Cat") {
  std::cout << "constructor Cat copy" << std::endl;
  _brain = new Brain(*src._brain);
}

Cat::~Cat(void) {
  std::cout << "destructor Cat" << std::endl;
  delete _brain;
}

void Cat::setBrainIdear(const std::string &idea, unsigned int offset) {
  if (offset >= 100)
    return;
  _brain->ideas[offset] = idea;
}

std::string Cat::getBrainIdear(unsigned int offset) {
  if (offset < 100)
    return _brain->ideas[offset];
  return "";
}

void Cat::makeSound(void) const {
  std::cout << "maiu miau i'm the cat" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain->operator=(*src._brain);
  return (*this);
}
