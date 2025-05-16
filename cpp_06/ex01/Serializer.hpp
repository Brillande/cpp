/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:09:32 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/16 15:22:57 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

struct Data 
{
	unsigned long raw;
};
  
class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer&	operator=(Serializer const &assign);
		~Serializer(void);
	public:
		static unsigned long serialize(Data* ptr);
		static Data* deserialize(unsigned long raw);
};
