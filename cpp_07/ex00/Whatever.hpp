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

//template lo que hace es que puede recibir cualquier tipo de variable por ejemplo int o double o float etc
template<typename T>
T const	&max(T const &x, T const &y)
{
    //en el return usamos un operador ternario que funciona de la siguiente forma si x es mayor que y devuelve x si no y
	return (x > y ? x : y);
}

template<typename T>
T const	&min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template<typename T>
void	swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
	return ;
}
