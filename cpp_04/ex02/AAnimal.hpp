/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:52:48 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 19:13:37 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
/* 
En Programación Orientada a Objetos (POO), virtualizar se 
refiere a la capacidad de hacer que un método en una clase
base sea sobrescrito (o redefinido) en clases derivadas,
permitiendo que se ejecute la versión específica de la
clase derivada en lugar de la de la clase base, incluso
si se hace una llamada a través de un puntero o referencia de la clase base.

En C++, esto se logra utilizando la palabra clave 
virtual en el método de la clase base. Cuando un método 
está marcado como virtual, permite que la llamada a ese método
 sea resuelta en tiempo de ejecución (esto se llama polimorfismo
dinámico o late binding), lo que significa que se invocará el método
correspondiente de la clase derivada en lugar del método de la clase base. */

class AAnimal {
public:
  AAnimal(const std::string &type);
  AAnimal(const AAnimal &src);
  AAnimal(void);
  virtual ~AAnimal(void);

  virtual const std::string &getType(void) const;

  virtual void makeSound(void) const = 0;

  virtual AAnimal &operator=(AAnimal const &src);

protected:
  std::string _type;
};
