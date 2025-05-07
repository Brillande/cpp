/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:54:12 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/07 13:42:29 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL ; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    // Prueba de array vacío
    Array<int> emptyArray;
    std::cout << "Tamaño de emptyArray: " << emptyArray.size() << std::endl;

    // Prueba de inicialización y acceso
    for (int i = 0; i < MAX_VAL; i++)
        numbers[i] = i;

    std::cout << "Contenido de numbers: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    // Prueba de copia y asignación
    Array<int> copy(numbers);
    Array<int> assigned;
    assigned = numbers;

    std::cout << "Contenido de copy: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    std::cout << "Contenido de assigned: ";
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << assigned[i] << " ";
    std::cout << std::endl;

    // Prueba de acceso fuera de rango
    try {
        std::cout << numbers[-1] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Excepción capturada (índice -1): " << e.what() << std::endl;
    }
    try {
        std::cout << numbers[MAX_VAL] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Excepción capturada (índice MAX_VAL): " << e.what() << std::endl;
    }

    // Prueba con otro tipo de dato
    Array<std::string> strArray(3);
    strArray[0] = "Hola";
    strArray[1] = "Mundo";
    strArray[2] = "!";
    std::cout << "Contenido de strArray: ";
    for (size_t i = 0; i < strArray.size(); ++i)
        std::cout << strArray[i] << " ";
    std::cout << std::endl;

    // Prueba de autoasignación
    numbers = numbers;
    std::cout << "Autoasignación realizada correctamente." << std::endl;
    delete[] mirror;
    return 0;
}