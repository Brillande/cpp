/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:25:39 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:09:32 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>


int main() 
{
    std::string myString = "HI THIS IS BRAIN";
    std::string *stringPTR = &myString;

    std::string &stringREF = myString;

    std::cout << "Address of myString: " << &myString << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "Value of myString: " << myString << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;

    return 0;
}