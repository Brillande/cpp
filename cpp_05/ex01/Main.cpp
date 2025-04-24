/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:51:29 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:51:30 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
int main(void)
{

	Bureaucrat manolo("manolo", 100);
	Bureaucrat paco("paco", 1);

	Form willy("willy", 10, 5);

	paco.SignForm(willy);
	manolo.SignForm(willy);

    try 
    {
        Form ellande("ellande", 10, 1);
		std::cout << ellande << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "ellande" << e.what() << std::endl;
	}

    try 
    {
        Form maialen("maialen", 109, 0);
		std::cout << maialen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "maialen " << e.what() << std::endl;
	}

    try 
    {
        Form Ugo("ugo", 5, 160);
		std::cout << Ugo << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Ugo " << e.what() << std::endl;
	}

    try 
    {
        Form Luis("Luis Maria", 5, 20);
		std::cout << Luis << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Luis Maria " << e.what() << std::endl;
	}

    try 
    {
        Form charo("charo", 300, 20);
		std::cout << charo << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "charo " << e.what() << std::endl;
	}

    try 
    {
        Form koldo("koldo", 0, 20);
		std::cout << koldo << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "koldo " << e.what() << std::endl;
	}

}