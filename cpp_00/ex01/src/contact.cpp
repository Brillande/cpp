/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:35:36 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 16:31:35 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook_class.hpp"
using namespace std;

Contact::Contact(string first_name, string lastname, string nickname, string phone_number, string darkest_secret)
{
    this->first_name = first_name;
    this->lastname = lastname;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

int     Contact::null(Contact contact)
{
    if (contact.first_name.empty())
        return (1);
    return (0);
}

void    Contact::print_info(Contact contact, int i)
{
    if (i == 1)
    {
       /*  Si el nombre tiene más de 10 caracteres:
Usa un rango de iteradores (contact.first_name.begin() a contact.first_name.begin() + 9) para tomar los primeros 9 caracteres del nombre.
Agrega un punto (.) al final para indicar que el nombre fue truncado.
Ejemplo: Si el nombre es "Christopher", se imprimirá como "Christophe.". */
        if (contact.first_name.size() > 10)
            cout << string(contact.first_name.begin(), contact.first_name.begin() + 9) << '.';
        else
        /* Si el nombre tiene 10 caracteres o menos:
Usa setw(10) para alinear el texto a la derecha en un espacio de 10 caracteres.
Ejemplo: Si el nombre es "John", se imprimirá como "      John" (con espacios a la izquierda). */
            cout << setw(10) << contact.first_name;
    }
    if (i == 2)
    {
        if (contact.lastname.size() > 10)
            cout << string(contact.lastname.begin(), contact.lastname.begin() + 9) << '.';
        else
            cout << setw(10) << contact.lastname;
    }
    if (i == 3)
    {
        if (contact.nickname.size() > 10)
            cout << string(contact.nickname.begin(), contact.nickname.begin() + 9) << '.';
        else
            cout << setw(10) << contact.nickname;
    }
}

void    Contact::print_contacts(Contact contact)
{
    cout << "First name: " << contact.first_name << "\n";
    cout << "Last name: " << contact.lastname << "\n";
    cout << "Nickname: " << contact.nickname << "\n";
    cout << "Phone number: " << contact.phone_number << "\n";
    cout << "Darkest secret: " << contact.darkest_secret << "\n";
}