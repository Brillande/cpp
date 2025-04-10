/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:52:36 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:48:16 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(const std::string &type) : _type(type){
	std::cout << "constructor AAnimal string" << std::endl;
}
AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << "constructor AAnimal empty" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
  if (this != &src)
    *this = src;
  std::cout << "constructor AAnimal copy" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "destructor AAnimal empty" << std::endl;
}

const std::string &AAnimal::getType(void) const { return _type; }

void AAnimal::makeSound(void) const {
  std::cout << "chuterstock animal" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
