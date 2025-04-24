/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:54:28 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:54:29 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
  public:
    AForm (const std::string &Name, int MinimumGradeSign, int MinimumGradeExecute);
    AForm (const AForm &Src);
    AForm ();
    virtual ~AForm ();

    AForm &operator=(AForm const &src);

    const std::string &GetName() const;
    bool               GetIsSigned() const;
    int                GetMinimumGradeSign() const;
    int                GetMinimumGradeExecute() const;

    void        execute(const Bureaucrat &b) const;
	  void				BeSigned(const Bureaucrat &b);

    class ErrorSign : public std::exception
    {
        public:
          virtual const char *what() const throw();
    };
    private:
      std::string _Name;
      bool        _IsSigned;
      const int   _MinimumGradeSign;
      const int   _MinimumGradeExecute;

      void _CheckGrade() const;
      virtual void _interExecute(const Bureaucrat &b) const = 0;
};
std::ostream& operator<<(std::ostream& o, const AForm& a);