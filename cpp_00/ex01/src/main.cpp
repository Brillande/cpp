/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:35:28 by emedina-          #+#    #+#             */
/*   Updated: 2024/09/09 17:35:21 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook_class.hpp"
using namespace std;

int main (void)
{
	string input;
	while (1)
	{
		cout << "input ADD, SEARCH or EXIT\n";
		getline(cin,input);
		if(input == "EXIT" || input == "exit")
			exit (EXIT_SUCCESS);
		else if(input == "ADD" || input == "add")
		{
			
		}
	}
}