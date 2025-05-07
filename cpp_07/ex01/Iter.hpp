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

template<typename T>
void	iter(T *array, size_t length, void (*f)(T))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
	return ;
}

template<typename T>
void	print(T member)
{
	std::cout << member << " ";
	return ;
}

void printLowerChar(char c) 
{
    std::cout << static_cast<char>(std::tolower(c)) << " ";
}

void printLowerString(std::string s)
{
    for (size_t i = 0; i < s.size(); ++i)
        std::cout << static_cast<char>(std::tolower(s[i]));
    std::cout << " ";
}
