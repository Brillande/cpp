/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:55:17 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:55:18 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  public:
    PresidentialPardonForm(const std::string &name);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm(void);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
  private:
	  void _interExecute(const Bureaucrat &b) const;
};
