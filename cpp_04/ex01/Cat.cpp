/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:53:08 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:05:20 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using namespace std;

Cat::Cat(void) : Animal("Cat") {
  cout << "constructor Cat empty" << endl;
  _brain = new Brain;
}

Cat::Cat(const Cat &src) : Animal("Cat") {
  cout << "constructor Cat copy" << endl;
  if (this != &src)
    *this = src;
  _brain = new Brain;
}

Cat::~Cat(void) {
  cout << "destructor Cat" << endl;
  delete _brain;
}

void Cat::setBrainIdear(const string &idea, unsigned int offset) {
  if (offset >= 100)
    return;
  _brain->ideas[offset] = idea;
}

string Cat::getBrainIdear(unsigned int offset) {
  if (offset < 100)
    return _brain->ideas[offset];
  return "";
}

void Cat::makeSound(void) const {
  cout << "maiu miau i'm the cat" << endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this == &src)
    return (*this);
  this->_type = src.getType();
  this->_brain->operator=(*src._brain);
  return (*this);
}
