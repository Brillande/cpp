/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:55:30 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 18:18:02 by emedina-         ###   ########.fr       */
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
	std::cout << "MEOW MEOW i'm the Wrong cat" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
