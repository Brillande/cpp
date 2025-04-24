/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:52:20 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:52:21 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try 
	{
		Bureaucrat manolo("manolo", 150);
		Bureaucrat patxi("patxi", 130);

		AForm *willy = new ShrubberyCreationForm("willy");

		manolo.executeForm(*willy);
		patxi.executeForm(*willy);

		manolo.SignForm(*willy);
		patxi.SignForm(*willy);

		manolo.executeForm(*willy);
		patxi.executeForm(*willy);

		delete willy;
	}
	catch (const std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat ellande("ellande", 1);

		AForm *willy = new RobotomyRequestForm("willy");
		ellande.SignForm(*willy);

		ellande.executeForm(*willy);

		delete willy;
	}
	catch (const std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat maialen("maialen", 1);

		AForm *willy = new PresidentialPardonForm("willy");
		maialen.SignForm(*willy);

		maialen.executeForm(*willy);

		delete willy;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat salamanca("salamanca", 1);

		AForm *willy = new ShrubberyCreationForm("willy");
		salamanca.SignForm(*willy);

		salamanca.executeForm(*willy);

		delete willy;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

}