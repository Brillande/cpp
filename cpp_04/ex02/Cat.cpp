/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:53:51 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:17:39 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using namespace std;

Cat::Cat(void) : AAnimal("Cat") {
  cout << "constructor Cat empty" << endl;
  _brain = new Brain;
}

Cat::Cat(const Cat &src) : AAnimal("Cat") {
  cout << "constructor Cat copy" << endl;
  if (this != &src)
    *this = src;
  _brain = new Brain;
}

Cat::~Cat(void) {
  cout << "destructor Cat" << endl;
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
  std::cout << "miau miau i'm the cat" << std::endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain->operator=(*src._brain);
  return (*this);
}
