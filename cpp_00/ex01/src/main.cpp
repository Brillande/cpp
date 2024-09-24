/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:35:28 by emedina-          #+#    #+#             */
/*   Updated: 2024/09/20 09:53:54 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook_class.hpp"
using namespace std;

void start(int i)
{
    string input;
	static Phonebook phonebook;
    int j;
    j = 0;

    while (1)
	{
		cout << "input ADD, SEARCH or EXIT\n";
		getline(cin,input);
        if(cin.eof() == 1)
            exit (EXIT_SUCCESS);
		if(input == "EXIT" || input == "exit")
			exit (EXIT_SUCCESS);
		else if(input == "ADD" || input == "add")
        {
            i = phonebook.check_phonebook(phonebook);
            if (i >= 8)
            {
                i = -1;
            while (i == -1)
            {
                cout << "Your oldest contact was gona delete with the new one \nnare u agree? Y or N\n";
                getline(cin, input);
                if(cin.eof() == 1)
                    exit (EXIT_SUCCESS);
                if (input == "Y" || input == "y")
                {
                    i = j;
                    j++;
                    if (j == 8)
                        j = 0;
                    phonebook = phonebook.add_iterator(phonebook, i);
                    i = 8;
                }
                else if (input == "N" || input == "n")
                    start(i);
                else
                    cout << "not valid input\n";
            }
        }
        if (i >= 0 && i < 8)
            phonebook = phonebook.add_iterator(phonebook, i);
    }
    else if (input == "SEARCH" || input == "search")
        phonebook.display(phonebook);
    else if (input.empty())
        continue ;
    else
        cout << "wrong command\n";
    }
}

int main (void)
{
    int i;

    i = 0;
    start(i);
}
