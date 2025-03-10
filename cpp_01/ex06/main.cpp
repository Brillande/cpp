/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:23:52 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/10 12:23:53 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

using namespace std;

int	main(int ac, char **av) 
{
	if (ac != 2) {
		cout << "[ Probably complaining about insignificant problems ]" << endl; return 0;
	}
	
	Harl	Harl;
	
	Harl.complain(av[1]);
}