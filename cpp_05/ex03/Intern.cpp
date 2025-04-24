/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:54:51 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:54:52 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "constructor Intern empty" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << "constructor Intern copy" << std::endl;
    if (this != &src)
        *this = src;
}

Intern::~Intern(void)
{
    std::cout << "destructor Intern" << std::endl;
}

Intern &Intern::operator=(Intern const &src) 
{
    if (this == &src)
        return (*this);
    return (*this);
}

static AForm *createPresidentialPardon(const std::string target) 
{
    return new PresidentialPardonForm(target);
}

static AForm *createRobotomyRequest(const std::string target) 
{
    return new RobotomyRequestForm(target);
}

static AForm *createShrubberyCreation(const std::string target) 
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string target,
                        const std::string name) const 
{
    std::string formNames[] = 
    {
        "presidential pardon", "robotomy request",
                               "shrubbery creation"
    };
    AForm      *(*formConstructors[])(const std::string) = 
    {
        &createPresidentialPardon, &createRobotomyRequest,
        &createShrubberyCreation
    };

    for (int i = 0; i < 3; i++) 
    {
        if (formNames[i] == target) 
        {
            AForm *ptr = formConstructors[i](name);
            std::cout << "Intern create : " << *ptr << std::endl;
            return ptr;
        }
    }
    std::cout << "Inter can't create : " << target << std::endl;
    return NULL;
}
