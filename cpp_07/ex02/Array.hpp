/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:54:24 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/07 11:54:25 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>
#include <iostream>
#include <cstdlib>
#include <string>

// Define el tamaño por defecto del array (no se usa en este código)
#define ARRAY_SIZE 1500

// Plantilla de clase: array dinámico genérico que puede almacenar elementos de cualquier tipo
// T: tipo genérico de los elementos que se almacenarán en el array
template<typename T>
class Array
{
	private:
        T*				array;			// Puntero al array dinámico
		unsigned int	 n;				// Tamaño del array (número de elementos)
	public:
		// Retorna el tamaño del array (número de elementos)
		unsigned int	size(void) const;

		// Constructores
		Array(void);					// Constructor por defecto: crea array vacío (NULL, tamaño 0)
		Array(unsigned int n);			// Constructor con tamaño: crea array de n elementos inicializados
		Array(Array const &src);		// Constructor de copia: crea una copia del array
		
		// Operadores
		Array&	operator=(Array const &assign);	// Operador de asignación: copia el contenido
		T&		operator[](unsigned int index);	// Operador de índice: acceso a elementos con verificación de límites
		
		// Destructor: libera la memoria del array
		~Array(void);
		
		// Excepción personalizada: se lanza cuando se intenta acceder fuera de los límites del array
		class OutOfBoundsException : public std::exception
		{
			public:
				// Retorna un mensaje de error cuando se accede fuera de los límites
				virtual const char* what() const throw()
				{
					return ("Out of bounds.");
				}	
		};
};
#include "Array.tpp"