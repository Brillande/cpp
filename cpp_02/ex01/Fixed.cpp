/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:22:52 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/26 10:53:53 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) 
{
	std ::cout << "Default constructor called" << std ::endl;
}

Fixed::Fixed(Fixed const &src) 
{
	std ::cout << "Copy constructor called" << std ::endl;
	*this = src;
}

Fixed::Fixed(const int n) 
{
	std ::cout << "Int constructor called" << std ::endl;
	this->value = n << bits;
}

Fixed::Fixed(const float f) : value(f) 
{
	std ::cout << "Float constructor called" << std ::endl;
	this->value = roundf(f * (1 << bits));
}

Fixed::~Fixed() 
{
	std ::cout << "Destructor called" << std ::endl;
}

Fixed&	Fixed::operator=(Fixed const &rSym) 
{
	std ::cout << "Copy assignement operator called" << std ::endl;
	if (this != &rSym)
		this->value = rSym.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const 
{
	std ::cout << "getRawBits member function called" << std ::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) 
{
	this->value = raw;
}

//para convertir float en punto fijo y poder asignarselo a un entero
float	Fixed::toFloat() const 
{
	return (float)this->value / (float)(1 << bits);
}

int		Fixed::toInt() const 
{
	return this->value >> bits;
}

std::ostream&	operator<<(std::ostream& o, Fixed const &rSym) 
{
	o << rSym.toFloat();
	return o;
}