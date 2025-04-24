/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:53:01 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:53:03 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(const ShrubberyCreationForm &ref);
        ShrubberyCreationForm(const std::string &name);
        ShrubberyCreationForm(void);
        ~ShrubberyCreationForm(void);

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

        class ErrorOpen : public std::exception
        {
            public:
            virtual const char *what() const throw();
        };
    private:
	    void _interExecute(const Bureaucrat &b) const;
};
