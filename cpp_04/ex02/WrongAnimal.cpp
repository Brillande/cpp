/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:08 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:50:49 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string &type) : _type(type) {
	std::cout << "WrongAnimal constructor string" << std::endl;
}

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal constructor empty" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  if (this != &src)
    *this = src;
  std::cout << "WrongAnimal constructor copy" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destructor" << std::endl;
}

const std::string &WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const {
  std::cout << "chuterstock animal from Wrong Animal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
