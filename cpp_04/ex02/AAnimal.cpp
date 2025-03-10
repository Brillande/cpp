/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:52:36 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:16:44 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

using namespace std;

AAnimal::AAnimal(const std::string &type) : _type(type){
	cout << "constructor AAnimal string" << endl;
}
AAnimal::AAnimal(void) : _type("AAnimal") {
	cout << "constructor AAnimal empty" << endl;
}

AAnimal::AAnimal(const AAnimal &src) {
  if (this != &src)
    *this = src;
  cout << "constructor AAnimal copy" << endl;
}

AAnimal::~AAnimal(void) {
	cout << "destructor AAnimal empty" << endl;
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
