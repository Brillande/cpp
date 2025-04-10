/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:54:02 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:43:39 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
  std ::cout << "constructor Dog empty" << std ::endl;
  _brain = new Brain;
}

Dog::Dog(const Dog &src) : Animal("Dog") {
	std ::cout << "constructor Dog copy" << std ::endl;
  _brain = new Brain(*src._brain);
}

Dog::~Dog(void) {
  std ::cout << "destructor Dog" << std ::endl;
  delete _brain;
}

void Dog::setBrainIdear(const std::string &idea, unsigned int offset) {
  if (offset >= 100)
    return;
  _brain->ideas[offset] = idea;
}

std::string Dog::getBrainIdear(unsigned int offset) {
  if (offset < 100)
    return _brain->ideas[offset];
  return "";
}

void Dog::makeSound(void) const {
  std ::cout << "guau guau i'm the dog" << std ::endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain->operator=(*src._brain);
  return (*this);
}
