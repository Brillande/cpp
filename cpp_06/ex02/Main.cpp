/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:58:12 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 16:02:24 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

// Programa principal: demuestra el casting dinámico (dynamic_cast)
int main(void)
{
	// Genera aleatoriamente un objeto A, B o C y retorna un puntero Base*
	Base *ellande = generate();
	
	// Identifica el tipo usando la versión con puntero (dynamic_cast retorna NULL si falla)
	std::cout << "pointer identifer : ";
	identify(ellande);
	
	// Identifica el tipo usando la versión con referencia (dynamic_cast lanza excepción si falla)
	std::cout << "ref identifer : ";
	identify(*ellande);	// Dereferencia el puntero para pasar la referencia
	
	// Libera la memoria del objeto creado dinámicamente
	delete ellande;
}
