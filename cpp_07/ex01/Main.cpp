/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:54:46 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/07 11:54:47 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main( void ) 
{
	std::cout << "Test Strings" << std::endl;
	std::string	iter_strings[7] = {"PAELLA", "TORTILLA", "JAM", "STEAK", "EGGS","SAUSAGES","FRIES"};

    iter(iter_strings, 7, print);
    std::cout << std::endl;
    iter(iter_strings,7,printLowerString);

	std::cout << "\ntest Ints" << std::endl;
	int	iter_int[7] = {26, 0, 344, 57, 8, 16, 222};
    iter(iter_int, 7, print);

    std::cout << "\nTest Chars" << std::endl;
	char	iter_char[7] = {'T', 'M', 'L', 'H', 'J', 'G', 'S'};
    iter(iter_char, 7, printLowerChar);
    std::cout << std::endl;
    iter(iter_char, 7, print);
	return (0);

}