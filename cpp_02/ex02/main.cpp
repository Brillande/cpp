/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:22:38 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:22:39 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

using namespace std;

int main( void ) {
 	Fixed a;
 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
 	std::cout << a << std::endl;
 	std::cout << a++ << std::endl;
 	std::cout << a << std::endl;

 	std::cout << b << std::endl;
	
 	std::cout << Fixed::max( a, b ) << std::endl;
 	return 0;
}