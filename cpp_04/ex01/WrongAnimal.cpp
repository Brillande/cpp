/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:55:06 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 13:06:58 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

using namespace std;

WrongAnimal::WrongAnimal(const string &type) : _type(type) {
	cout << "WrongAnimal constructor string" << endl;
}

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	cout << "WrongAnimal constructor empty" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
  if (this != &src)
    *this = src;
  cout << "WrongAnimal constructor copy" << endl;
}

WrongAnimal::~WrongAnimal(void) {
  cout << "WrongAnimal destructor" << endl;
}

const string &WrongAnimal::getType(void) const { return _type; }

void WrongAnimal::makeSound(void) const {
  cout << "chuterstock animal from Wrong Animal" << endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
