/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:51:18 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:53:54 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &Name, int MinimumGradeSign,
    int MinimumGradeExecute)
    : _Name(Name),
      _MinimumGradeSign(MinimumGradeSign),
      _MinimumGradeExecute(MinimumGradeExecute) 
{
    std::cout << "default constructor" << std::endl;
    _CheckGrade();
}

Form::Form(const Form &Src)
: _Name(Src.GetName()),
  _IsSigned(Src.GetIsSigned()),
  _MinimumGradeSign(Src.GetMinimumGradeSign()),
  _MinimumGradeExecute(Src.GetMinimumGradeExecute()) 
{
    std::cout << "constructor Form copy" << std::endl;
    _CheckGrade();
}

Form::~Form(void)
{
    std::cout << "destructor Form" << std::endl;
}

Form &Form::operator=(Form const &Src) 
{
    if (this == &Src)
    return (*this);
    _IsSigned = Src.GetIsSigned();
    _Name = Src.GetName();
    return (*this);
}

Form::Form(void)
: _Name ("default"),
_IsSigned(false),
_MinimumGradeSign(MinBureaucratGrade),
_MinimumGradeExecute(MinBureaucratGrade) 
{
    std::cout << "constructor Form empty" << std::endl;
}

/* getter */

const std::string &Form::GetName() const 
{
    return _Name; 
}

bool Form::GetIsSigned() const 
{ 
    return _IsSigned; 
}

int Form::GetMinimumGradeSign() const 
{ 
    return _MinimumGradeSign; 
}

int Form::GetMinimumGradeExecute() const 
{ 
    return _MinimumGradeExecute; 
}

void Form::BeSigned(const Bureaucrat &b) 
{
    if (b.GetGrade() > _MinimumGradeSign)
    throw Bureaucrat::GradeLowException();
    _IsSigned = true;
}

void Form::_CheckGrade() const 
{
    if (_MinimumGradeSign > MinBureaucratGrade || _MinimumGradeExecute > MinBureaucratGrade)
    throw Bureaucrat::GradeLowException();
    if (_MinimumGradeSign < MaxBureaucratGrade || _MinimumGradeExecute < MaxBureaucratGrade)
    throw Bureaucrat::GradeHighException();
}

std::ostream &operator<<(std::ostream &o, const Form &a) 
{
    o << "name: " << a.GetName() << " minimun grade to sign: " << a.GetMinimumGradeSign()
    << ", minimun grade to execute: " << a.GetMinimumGradeExecute() << std::endl;
    return o;
}