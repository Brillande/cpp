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
#include <stdlib.h>
#include <string>
#include <cstdlib>
#define ARRAY_SIZE 1500
template<typename T>
class Array
{
	private:
        T*				array;
		unsigned int	 n;
	public:

		unsigned int	size(void) const;

		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		Array&	operator=(Array const &assign);
		T&		operator[](unsigned int index);
		~Array(void);
		
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Out of bounds.");
				}	
		};
};
#include "Array.tpp"