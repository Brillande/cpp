/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:36:36 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 15:58:01 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>
#include <immintrin.h>

// Clase base abstracta con destructor virtual
// El destructor virtual es necesario para usar dynamic_cast correctamente
class Base 
{
	public:
		virtual ~Base();	// Destructor virtual: permite polimorfismo y casting dinámico
};

// Clases derivadas: A, B y C heredan de Base
// Se usan para demostrar el casting dinámico (dynamic_cast)
class A : public Base 
{
    // Clase derivada A (vacía, solo para demostración de casting)
};
class B : public Base 
{
    // Clase derivada B (vacía, solo para demostración de casting)
};
class C : public Base 
{
    // Clase derivada C (vacía, solo para demostración de casting)
};

// Funciones para identificar el tipo real de un objeto Base
// identify(Base& p):  identifica el tipo usando referencia (usa try-catch)
// identify(Base* p):  identifica el tipo usando puntero (usa dynamic_cast)
// generate(void):    genera aleatoriamente un objeto A, B o C y retorna un puntero Base
void identify(Base& p);		// Identifica el tipo usando referencia (lanza excepción si falla)
void identify(Base* p);		// Identifica el tipo usando puntero (retorna NULL si falla)
Base *generate(void);		// Genera aleatoriamente una instancia de A, B o C