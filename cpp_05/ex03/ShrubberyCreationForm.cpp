/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:55:36 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:55:37 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define MIN_SIGN 145
#define MIN_EXEC 137

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
    : AForm(name, MIN_SIGN, MIN_EXEC) 
{
    std::cout << "constructor ShrubberyCreationForm string name" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src) 
{
    std::cout << "constructor ShrubberyCreationForm copy" << std::endl;
    if (this != &src)
        *this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("default_shrubbery", MIN_SIGN,
            MIN_EXEC)
{
    std::cout << "constructor ShrubberyCreationForm empty" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "destructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &src) 
{
    if (this == &src)
        return (*this);
    return (*this);
}

void ShrubberyCreationForm::_interExecute(const Bureaucrat &b) const {

	std::ofstream outfile(std::string(b.GetName() + "_shrubbery").c_str());
    if (!outfile.is_open()) {
        throw ShrubberyCreationForm::ErrorOpen();
    }

outfile     << "     /\\                 /\\                 /\\\n"
            << "    /  \\               /  \\               /  \\\n"
            << "   /    \\             /    \\             /    \\\n"
            << "  /      \\           /      \\           /      \\\n"
            << " /        \\         /        \\         /        \\\n"
            << "/__________\\       /__________\\       /__________\\\n"
            << "     | |       O        | |        O       | |\n"
            << "     | |      OoO       | |       OoO      | |\n"
            << "     | |      oOo       | |       oOo      | |\n"
            << "_____| |_______|________| |________|_______| |_____\n";

    outfile.close();
}

const char *ShrubberyCreationForm::ErrorOpen::what(void) const throw()
{
	return ("Error opening the form");
}