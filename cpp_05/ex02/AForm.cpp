/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:51:48 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:53:38 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &Name, int MinimumGradeSign,
    int MinimumGradeExecute)
    : _Name(Name),
      _MinimumGradeSign(MinimumGradeSign),
      _MinimumGradeExecute(MinimumGradeExecute) 
{
    std::cout << "default constructor" << std::endl;
    _CheckGrade();
}

AForm::AForm(const AForm &Src)
: _MinimumGradeSign(Src.GetMinimumGradeSign()),
_MinimumGradeExecute(Src.GetMinimumGradeExecute()) 
{
    std::cout << "constructor AForm copy" << std::endl;
    if (this != &Src)
    *this = Src;
    _CheckGrade();
}

AForm::~AForm(void)
{
    std::cout << "destructor AForm" << std::endl;
}

AForm &AForm::operator=(AForm const &Src) 
{
    if (this == &Src)
    return (*this);
    _IsSigned = Src.GetIsSigned();
    _Name = Src.GetName();
    return (*this);
}

AForm::AForm(void)
: _Name ("default"),
_IsSigned(false),
_MinimumGradeSign(MinBureaucratGrade),
_MinimumGradeExecute(MinBureaucratGrade) 
{
    std::cout << "constructor AForm empty" << std::endl;
}

/* getter */

const std::string &AForm::GetName() const 
{
    return _Name; 
}

bool AForm::GetIsSigned() const 
{ 
    return _IsSigned; 
}

int AForm::GetMinimumGradeSign() const 
{ 
    return _MinimumGradeSign; 
}

int AForm::GetMinimumGradeExecute() const 
{ 
    return _MinimumGradeExecute; 
}

void AForm::execute(const Bureaucrat &b) const 
{
    if (_IsSigned == false)
        throw AForm::ErrorSign();
    if (b.GetGrade() > _MinimumGradeExecute)
        throw Bureaucrat::GradeLowException();
    _interExecute(b);
}

void AForm::BeSigned(const Bureaucrat &b) 
{
    if (b.GetGrade() > _MinimumGradeSign)
    throw Bureaucrat::GradeLowException();
    _IsSigned = true;
}

void AForm::_CheckGrade() const 
{
    if (_MinimumGradeSign > MinBureaucratGrade || _MinimumGradeExecute > MinBureaucratGrade)
    throw Bureaucrat::GradeLowException();
    if (_MinimumGradeSign < MaxBureaucratGrade || _MinimumGradeExecute < MaxBureaucratGrade)
    throw Bureaucrat::GradeHighException();
}

std::ostream &operator<<(std::ostream &o, const AForm &a) 
{
    o << "name: " << a.GetName() << " minimun grade to sign: " << a.GetMinimumGradeSign()
    << ", minimun grade to execute: " << a.GetMinimumGradeExecute() << std::endl;
    return o;
}

const char *AForm::ErrorSign::what(void) const throw()
{
	return ("Error signing the form");
}