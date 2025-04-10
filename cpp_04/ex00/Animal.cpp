/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:18:23 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:45:59 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
/* 
El polimorfismo en la Programación Orientada a Objetos (POO) es uno
 de los conceptos clave de esta paradigma, y se refiere a la capacidad 
 de un objeto de tomar diferentes formas. En términos simples, el polimorfismo 
 permite que un objeto de una clase derivada sea tratado como si fuera un objeto 
 de su clase base, pero manteniendo su comportamiento específico de la clase derivada.
 */

Animal::Animal(const std::string &type) : _type(type){
	std::cout << "constructor Animal std::string" << std::endl;
}
Animal::Animal(void) : _type("Animal") {
	std::cout << "constructor Animal empty" << std::endl;
}

Animal::Animal(const Animal &src) {
  if (this != &src)
    *this = src;
  std::cout << "constructor Animal copy" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "destructor Animal empty" << std::endl;
}

const std::string &Animal::getType(void) const { return _type; }

void Animal::makeSound(void) const {
  std::cout << "chuterstock animal" << std::endl;
}

Animal &Animal::operator=(Animal const &src) {
  if (this != &src)
    this->_type = src.getType();
  return (*this);
}
