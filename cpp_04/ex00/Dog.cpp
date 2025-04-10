/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:53 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:46:10 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "constructor Dog empty" << std::endl;
}

Dog::Dog(const Dog &src) : Animal("Dog") {
  if (this != &src)
    *this = src;
  std::cout << "constructor Dog copy" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "destructor Dog" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "guau guau i'm the dog" << std::endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
