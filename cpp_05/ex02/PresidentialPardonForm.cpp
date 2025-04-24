/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:52:27 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:52:28 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#define MIN_SIGN 25
#define MIN_EXEC 5

// contructor and destructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
    : AForm(name, MIN_SIGN, MIN_EXEC) 
{
    std::cout << "constructor PresidentialPardonForm string name" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src) 
{
    std::cout << "constructor PresidentialPardonForm copy" << std::endl;
    if (this != &src)
        *this = src;
}

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("default_shrubbery", MIN_SIGN, MIN_EXEC) {
    std::cout << "constructor PresidentialPardonForm empty" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "destructor PresidentialPardonForm" << std::endl;
}

//overload
PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &src) 
{
    if (this == &src)
        return (*this);
    return (*this);
}

void PresidentialPardonForm::_interExecute(const Bureaucrat &b) const {
	 std::cout << b << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}