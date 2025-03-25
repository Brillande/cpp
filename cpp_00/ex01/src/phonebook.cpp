/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:34:28 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 16:34:03 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook_class.hpp"
using namespace std;

Phonebook::Phonebook(void)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

int isnum(string s, int i)
{
    if (s.size() != 1)
        return (0);
    if (48 <= s[0] && s[0] <= 48 + i)
        return (1);
    return (0);
}

string  add_info(string msg)
{
    string dest;
    
    cout << msg;
    while (1)
    {
        getline(cin, dest);
        if(cin.eof() == 1)
        {
            cout << "\n";
            exit (EXIT_SUCCESS);
        }
        //Elimina espacios en blanco iniciales y finales:
        dest.erase(0, dest.find_first_not_of(" \t\v\f\r"));
        while (isspace(dest[dest.length() - 1]))
            dest.erase(dest.find_last_not_of(" \t\v\r\f") + 1, dest[dest.length() - 1]);
        if (dest.empty())
            cout << "cant be empty\n." << msg;
        else
            break ;
    }
    return (dest);
}
// La línea Phonebook Phonebook::add_iterator es la declaración de una función miembro de la clase Phonebook. Aquí está el desglose de lo que significa:
Phonebook    Phonebook::add_iterator(Phonebook phonebook, int i)
{
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;
    int first;
    int last;
    int nick;
    int phone;
    int darkest;
    Contact new_contact(first_name = add_info("First name:"), last_name = add_info("Last name:"),
                        nickname = add_info("Nickname:"),phone_number = add_info("Phone number:"),
                        darkest_secret = add_info("Darkest secret:"));
    first = check_first_name(first_name);
    last = check_last_name(last_name);
    nick = check_nickname(nickname);
    phone = check_phonenumber(phone_number);
    darkest = check_darkest_secret(darkest_secret);

    if(first == 0 || last == 0
    || nick == 0 || phone == 0
    || darkest == 0)
    {
        cout << "contact no created\n";
        return phonebook;
    }
        
    phonebook.contacts[i] = new_contact;
    return phonebook;
}

int Phonebook::check_phonebook(Phonebook phonebook)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (phonebook.contacts[i].null(phonebook.contacts[i]))
            break ;
        i++;
    }
    return (i);
}

int Phonebook::check_first_name(string first_name)
{
    int i;

    i = 0;
    while(isalpha(first_name[i] == 1) || first_name[i] != '\0')
        i++;
    if(first_name[i] == '\0')
        i--;
    if(isalpha(first_name[i]) == 0)
        cout << "only alphabetic input in first name\n";
    return(isalpha(first_name[i]));
}

int Phonebook::check_last_name(string last_name)
{
    int i;

    i = 0;
    while(isalpha(last_name[i] == 1) || last_name[i] != '\0')
        i++;
    if(last_name[i] == '\0')
        i--;
    if(isalpha(last_name[i]) == 0)
        cout << "only alphabetic input in last name\n";
    return(isalpha(last_name[i]));
}

int Phonebook::check_nickname(string nickname)
{
    int i;

    i = 0;
    while(isprint(nickname[i] == 1) || nickname[i] != '\0')
        i++;
    if(nickname[i] == '\0')
        i--;
    if(isprint(nickname[i]) == 0)
        cout << "only printable input in nickname\n";
    return(isprint(nickname[i]));
}

int Phonebook::check_phonenumber(string phonenumber)
{
    int i;

    i = 0;
    while(isdigit(phonenumber[i] == 1) || phonenumber[i] != '\0')
        i++;
    if(phonenumber[i] == '\0')
        i--;
    if(isdigit(phonenumber[i]) == 0)
        cout << "only digits input in phonenumber\n";
    if(phonenumber.length() != 9)
    {
        cout << "the phonenumber need to has 9 digits\n";
        return (0);
    }
    return(isdigit(phonenumber[i]));
}

int Phonebook::check_darkest_secret(string darkest_secret)
{
    int i;

    i = 0;
    while(isalpha(darkest_secret[i] == 1) || darkest_secret[i] != '\0')
        i++;
    if(darkest_secret[i] == '\0')
        i--;
    if(isalpha(darkest_secret[i]) == 0)
        cout << "only alphabetic input in darkest secret\n";
    return(isalpha(darkest_secret[i]));
}

void        Phonebook::display(Phonebook phonebook)
{
    int i;
    int max;
    string index;

    i = 0;
    if (phonebook.contacts[0].null(phonebook.contacts[0]))
    {
        cout << "Your phonebook is empty\n";
        return ;
    }
    cout << "|-------------------------------------------|\n";
    cout << "|     Index|" << "First name|" << " Last name|" << "  Nickname|\n";
    cout << "|-------------------------------------------|\n";
    while (i < 8)
    {
        if (phonebook.contacts[i].null(phonebook.contacts[i]))
            break ;
        cout << "|" << setw(10) << i << "|";
        contacts[i].print_info(contacts[i], 1);
        cout << "|";
        contacts[i].print_info(contacts[i], 2);
        cout << "|";
        contacts[i].print_info(contacts[i], 3);
        cout << "|\n";
        cout << "|-------------------------------------------|\n";
        i++;
    }
    max = i - 1;
    while (1)
    {
        cout << "Please select the index for more info:";
        getline(cin, index);
        if(cin.eof() == 1)
        {
            cout << "\n";
            exit (EXIT_SUCCESS);
        }
        index.erase(0, index.find_first_not_of(" \t\v\f\r"));
        while (isspace(index[index.length() - 1]))
            index.erase(index.find_last_not_of(" \t\v\r\f") + 1, index[index.length() - 1]);
        if (index.empty())
            continue ;
        if (isnum(index, max))
            i = (int)index[0] - 48;
        else
        {
            cout << "input a valid number of index ty\n";
            return ;
        }
        phonebook.contacts[i].print_contacts(phonebook.contacts[i]);
        break ;
    }
    if (i == 8)
        i = 0;
}
