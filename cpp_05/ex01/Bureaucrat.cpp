/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:51:09 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/24 13:51:10 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//constructor and desctructor

Bureaucrat::Bureaucrat(void)
{
    std::cout << "default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &Src)
{
    std::cout << "copy contructor called" << std::endl;
    if(this != &Src)
        *this = Src;
}

Bureaucrat::Bureaucrat(const std::string &Name, int Grade) : _Name(Name)
{
    std::cout << "Name and Grade constructor" << std::endl;
    if (Grade > MinBureaucratGrade)
        throw(GradeLowException());
     if (Grade < MaxBureaucratGrade)
        throw(GradeHighException());
    
    _Grade = Grade;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "destructor called" << std::endl;
}

//Getters

int Bureaucrat::GetGrade() const
{
    return(_Grade);
}

const std::string &Bureaucrat::GetName() const
{
    return(_Name);
}

//son metodos modificadores.
void Bureaucrat::IncrementGrade() 
{
    (*this)++; 
}

void Bureaucrat::DecrementGrade() 
{
    (*this)--;
}

void Bureaucrat::SignForm(Form &form) {
    try 
    {
        form.BeSigned(*this);
        std::cout << *this << " signed " << form << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cout << *this << " cant sign " << form
                << e.what() << std::endl;
    }
}
//overload

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &Src) 
{
    if (this == &Src)
        return (*this);
    _Grade = Src.GetGrade();
    return (*this);
}

Bureaucrat &Bureaucrat::operator++(void) 
{
    _Grade--;
    if (_Grade < MaxBureaucratGrade)
        throw GradeHighException();
    return (*this);
}

Bureaucrat Bureaucrat::operator++(int) 
{
    Bureaucrat old = *this;
    if (_Grade - 1 < MaxBureaucratGrade)
        throw GradeHighException();
    _Grade--;
    return (old);
}

Bureaucrat &Bureaucrat::operator--(void) 
{
    _Grade++;
    if (_Grade > MinBureaucratGrade)
        throw GradeLowException();
    return (*this);
}
Bureaucrat Bureaucrat::operator--(int) 
{
    Bureaucrat old = *this;
    if (_Grade + 1 > MinBureaucratGrade)
        throw GradeLowException();
    _Grade++;
    return (old);
}

//Permite que puedas imprimir objetos de tipo Bureaucrat directamente con std::cout

std::ostream &operator<<(std::ostream &oStream, Bureaucrat &value) {
    oStream << value.GetName() << " Bureaucrat Grade " << value.GetGrade() << ".";
    return (oStream);
}

//exceptions

const char *Bureaucrat::GradeLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeHighException::what(void) const throw()
{
	return ("Grade too high");
}