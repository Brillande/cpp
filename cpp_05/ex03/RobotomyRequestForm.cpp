/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:55:22 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:55:24 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#define MIN_SIGN 72
#define MIN_EXEC 45

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) 
{
    std::cout << "constructor RobotomyRequestForm copy" << std::endl;
    if (this != &src)
        *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "destructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &src) 
{
    if (this == &src)
        return (*this);
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("default_shrubbery", MIN_SIGN,
            MIN_EXEC)
{
    std::cout << "constructor RobotomyRequestForm empty" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
    : AForm(name, MIN_SIGN, MIN_EXEC) 
{
    std::cout << "constructor RobotomyRequestForm string name" << std::endl;
}

void RobotomyRequestForm::_interExecute(const Bureaucrat &b) const 
{
    std::cout << "randomnazing" << std::endl;
    srand(time(0));
    if (rand() % 2 == 0) 
    {
        std::cout << " aprobbed " << b <<  std::endl;
    } 
    else 
    {
        std::cout << " dissaprobbed " << b << "." << std::endl;
    }
}
