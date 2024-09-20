/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:35:36 by emedina-          #+#    #+#             */
/*   Updated: 2024/09/18 11:25:42 by emedina-         ###   ########.fr       */
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
        if (contact.first_name.size() > 10)
            cout << string(contact.first_name.begin(), contact.first_name.begin() + 9) << '.';
        else
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