/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:55:00 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/07 11:55:01 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

// Plantilla de función: puede recibir cualquier tipo de variable (int, double, float, etc.)
// T es el tipo genérico que se deduce del tipo de los argumentos
// Retorna una referencia constante al valor mayor entre x e y
template<typename T>
T const	&max(T const &x, T const &y)
{
	// Operador ternario: si x es mayor que y, devuelve x; si no, devuelve y
	// La comparación usa el operador > del tipo T
	return (x > y ? x : y);
}

// Plantilla de función: retorna el valor menor entre dos valores
// Retorna una referencia constante al valor menor entre x e y
template<typename T>
T const	&min(T const &x, T const &y)
{
	// Operador ternario: si x es menor que y, devuelve x; si no, devuelve y
	// La comparación usa el operador < del tipo T
	return (x < y ? x : y);
}

// Plantilla de función: intercambia los valores de x e y
// Los parámetros son referencias no constantes para poder modificar sus valores
template<typename T>
void	swap(T &x, T &y)
{
	T temp = x;	// Guarda el valor de x en una variable temporal
	x = y;		// Asigna el valor de y a x
	y = temp;	// Asigna el valor guardado (el original de x) a y
	return ;
}
