/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:53 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 19:06:15 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using namespace std;

Dog::Dog(void) : Animal("Dog") {
	cout << "constructor Dog empty" << endl;
}

Dog::Dog(const Dog &src) : Animal("Dog") {
  if (this != &src)
    *this = src;
  cout << "constructor Dog copy" << endl;
}

Dog::~Dog(void) {
	cout << "destructor Dog" << endl;
}

void Dog::makeSound(void) const {
	cout << "guau guau i'm the dog" << endl;
}

Dog &Dog::operator=(Dog const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
