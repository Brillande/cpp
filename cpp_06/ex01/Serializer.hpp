/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:09:32 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/15 18:37:50 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ios>
#include <iostream>
#include <stdint.h>

// Estructura de datos de ejemplo con un campo raw de tipo uintptr_t
struct Data 
{
	uintptr_t raw;	// Campo que almacena un entero sin signo del tamaño de un puntero
};
  
// Clase estática para serializar y deserializar punteros
// Serializar: convertir un puntero a un entero (uintptr_t)
// Deserializar: convertir un entero (uintptr_t) de vuelta a un puntero
class Serializer
{
	private:
		// Constructor privado: previene la instanciación de la clase
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer&	operator=(Serializer const &assign);
		~Serializer(void);
	public:
		// Convierte un puntero a Data en un entero sin signo (uintptr_t)
		static uintptr_t serialize(Data* ptr);
		// Convierte un entero sin signo (uintptr_t) de vuelta a un puntero a Data
		static Data* deserialize(uintptr_t raw);
};
