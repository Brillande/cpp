/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:58:12 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 15:34:05 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Programa principal: demuestra la serialización y deserialización de punteros
int main(void)
{
	// Crea una instancia de Data
	Data ellande;

	// Asigna un valor al campo raw
	ellande.raw = 123456789;
	// Imprime la dirección del objeto y su valor raw
	std::cout << "ellande (" << &ellande << ") raw = " << ellande.raw << std::endl;

	// Serializa el puntero: convierte la dirección de memoria a un entero
	uintptr_t maialen = Serializer::serialize(&ellande);
	// Imprime el valor serializado (en hexadecimal y decimal)
	std::cout << "after serialize (0x" << std::hex << ") maialen of ellande " << maialen << std::dec << std::endl;

	// Deserializa el entero: convierte el entero de vuelta a un puntero
	Data *ugo = Serializer::deserialize(maialen);
	// Imprime la dirección del puntero deserializado y accede al campo raw
	std::cout << "after desserialize ugo (" << ugo << ") raw = " << ugo->raw << std::endl;
}
