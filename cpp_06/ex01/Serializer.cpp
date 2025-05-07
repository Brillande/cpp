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

// convierte un puntero a un entero sin signo
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
// convierte un entero sin signo a un puntero
Data* Serializer::deserialize(uintptr_t raw)
{
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
