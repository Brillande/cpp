/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:52 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:18:09 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) 
{
	if (ac != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	
	Harl	Harl;
	
	Harl.complain(av[1]);
}