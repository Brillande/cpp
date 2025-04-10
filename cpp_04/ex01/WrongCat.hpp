/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/04/10 13:58:04 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/10 13:58:05 by emedina-         ###   ########.fr       */
=======
/*   Created: 2025/03/26 18:08:23 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/26 18:08:24 by emedina-         ###   ########.fr       */
>>>>>>> 205bf8f307193d68bde3af2bbce6653b49249667
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "WrongAnimal.hpp"

// La clase WrongCat es una derivada de WrongAnimal. Está diseñada para
// demostrar una implementación "incorrecta" o "peculiar" en el contexto
// de la herencia en C++.
class WrongCat : public WrongAnimal {
public:
  WrongCat();                      // Constructor por defecto: inicializa un WrongCat.
  WrongCat(const WrongCat &src);   // Constructor de copia: crea una copia de un WrongCat existente.
  ~WrongCat();                     // Destructor: se encarga de liberar recursos si fuera necesario.

  // Operador de asignación: permite copiar el estado de otro WrongCat en el objeto actual.
  WrongCat &operator=(WrongCat const &src);

private:
  // Función privada que redefine el sonido: 
  // se espera que imprima el sonido específico de un WrongCat.
  void makeSound(void) const;
};
