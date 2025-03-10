/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:40 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:44:20 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using namespace std;

Cat::Cat(void) : Animal("Cat") {
	cout << "constructor Cat empty" << endl;
}

Cat::Cat(const Cat &src) : Animal("Cat") {
  if (this != &src)
    *this = src;
  cout << "constructor Cat copy" << endl;
}

Cat::~Cat(void) {
	cout << "destructor Cat" << endl;
}

void Cat::makeSound(void) const {
	cout << "Miau maiu i'm the cat" << endl;
}

Cat &Cat::operator=(Cat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
