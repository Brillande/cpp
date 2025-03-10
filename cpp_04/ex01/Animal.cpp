/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:46:23 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 13:03:05 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using namespace std;

Animal::Animal(const string &type) : _type(type){
	cout << "constructor Animal string" << endl;
}
Animal::Animal(void) : _type("Animal") {
	cout << "constructor Animal empty" << endl;
}

Animal::Animal(const Animal &src) {
  if (this != &src)
    *this = src;
  cout << "constructor Animal copy" << endl;
}

Animal::~Animal(void) {
	cout << "destructor Animal empty" << endl;
}

const string &Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  cout << "chuterstock animal" << endl;
}

Animal &Animal::operator=(Animal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
