/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:55:03 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:55:04 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
        Intern ellande;
        AForm *willy;
        willy = ellande.makeForm("shrubbery creation", "ellande");
        std::cout << *willy << std::endl;
		if (willy)
			delete willy;
    }
    {
        Intern maialen;
        AForm *willy;
        willy = maialen.makeForm("presidential pardon", "maialen");
        std::cout << *willy << std::endl;
		if (willy)
			delete willy;
    }
    {
        Intern ugo;
        AForm *willy;
        willy = ugo.makeForm("robotomy request", "ugo");
        std::cout << *willy << std::endl;
		if (willy)
			delete willy;
    }
    {
        Intern patxi;
        AForm *willy;
        willy = patxi.makeForm("jebofboefqb", "fallo");
		if (willy)
			delete willy;
    }

}