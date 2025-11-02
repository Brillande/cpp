/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:54:53 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/07 11:54:54 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstddef> 

// Plantilla de función: aplica una función a cada elemento de un array
// T: tipo genérico de los elementos del array
// array: puntero al primer elemento del array
// length: tamaño del array (número de elementos)
// f: puntero a función que toma un elemento de tipo T y no retorna nada (void)
template<typename T>
void	iter(T *array, size_t length, void (*f)(T))
{
	// Itera sobre todos los elementos del array
	for (size_t i = 0; i < length; i++)
		f(array[i]);	// Aplica la función f al elemento array[i]
	return ;
}

// Plantilla de función: imprime un elemento de cualquier tipo
// T: tipo genérico del elemento a imprimir
template<typename T>
void	print(T member)
{
	// Imprime el elemento seguido de un espacio
	std::cout << member << " ";
	return ;
}

// Función específica: convierte un carácter a minúscula e imprime
void printLowerChar(char c) 
{
	// Convierte el carácter a minúscula usando tolower() e imprime seguido de espacio
    std::cout << static_cast<char>(std::tolower(c)) << " ";
}

// Función específica: convierte un string a minúsculas e imprime
void printLowerString(std::string s)
{
	// Itera sobre todos los caracteres del string
    for (size_t i = 0; i < s.size(); ++i)
		// Convierte cada carácter a minúscula e imprime
        std::cout << static_cast<char>(std::tolower(s[i]));
	// Imprime un espacio al final
    std::cout << " ";
}
