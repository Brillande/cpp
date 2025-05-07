/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:09:32 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 15:55:10 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


struct Data 
{
	uintptr_t raw;
};
  
class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer&	operator=(Serializer const &assign);
		~Serializer(void);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
