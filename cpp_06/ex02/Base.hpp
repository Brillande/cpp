/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:36:36 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 15:58:01 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <iostream>
#include <immintrin.h>

class Base 
{
	public:
		virtual ~Base();
};

class A : public Base 
{
    
};
class B : public Base 
{
    
};
class C : public Base 
{
    
};

void identify(Base& p);
void identify(Base* p);
Base *generate(void);