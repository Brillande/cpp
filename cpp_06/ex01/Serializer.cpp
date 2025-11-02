/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:08:39 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 15:21:35 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Convierte un puntero a Data en un entero sin signo (uintptr_t)
// reinterpret_cast permite convertir entre tipos de punteros y enteros
// Útil para serializar punteros (almacenarlos como números)
uintptr_t Serializer::serialize(Data *ptr)
{
	// Convierte la dirección de memoria del puntero a un entero sin signo
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Convierte un entero sin signo (uintptr_t) de vuelta a un puntero a Data
// Útil para deserializar punteros (recuperarlos desde números)
Data* Serializer::deserialize(uintptr_t raw)
{
	// Convierte el entero de vuelta a un puntero a Data
	return (reinterpret_cast<Data*>(raw));
}

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
	return ;
}

Serializer &	Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return (*this);
}

Serializer::~Serializer(void)
{
	return ;
}
