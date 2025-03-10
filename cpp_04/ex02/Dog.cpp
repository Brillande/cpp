/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:54:27 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:17:43 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using namespace std;

Dog::Dog(void) : AAnimal("Dog") {
  cout << "constructor Dog empty" << endl;
  _brain = new Brain;
}

Dog::Dog(const Dog &src) : AAnimal("Dog") {
	cout << "constructor Dog copy" << endl;
  if (this != &src)
    *this = src;
  _brain = new Brain;
}

Dog::~Dog(void) {
  cout << "destructor Dog" << endl;
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
  std::cout << "guau guau i'm the dog" << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain->operator=(*src._brain);
  return (*this);
}
