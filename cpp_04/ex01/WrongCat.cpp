/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:56:20 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 13:07:14 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

using namespace std;

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	cout << "constructor WrongCat empty" << endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal("WrongCat") {
  if (this != &src)
    *this = src;
  cout << "constructor WrongCat copy" << endl;
}

WrongCat::~WrongCat(void) {}

void WrongCat::makeSound(void) const {
	cout << "MEOW MEOW i'm the Wrong cat" << endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
