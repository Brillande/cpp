/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:57:59 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 15:37:33 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cerrno>
#include <ostream>
#include <iomanip>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <limits.h>
#include <stdlib.h>
#include <cmath>

// Definiciones de tipos para identificar qué tipo de dato es la entrada
#define typeChar 0		
#define typePseudo 1
#define typeInt 2	
#define typeFloat 3	
#define typeDouble 4	

// Clase estática para convertir un string a char, int, float y double
// No se puede instanciar (constructor privado)
class ScalarConverter
{
	private:
		// Variables estáticas para almacenar los valores convertidos
		static char		theChar;	// Valor convertido a char
		static int		theInt;		
		static float	theFloat;	
		static double	theDouble;	
        // Constructor privado: previene la instanciación de la clase
        ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);
        
		// Funciones que imprimen la conversión según el tipo detectado
        static void		isChar(void);		// Imprime conversión desde char
		static void		isInt(void);		
		static void		isFloat(void);		
		static void		isDouble(void);		
        static void		isPseudo(void);	

        // Funciones que verifican si el string puede ser de un tipo específico
        static int		checkInt(double convertedDouble, std::string toConvert);		// Verifica si es int
		static int		checkFloat(double convertedDouble, std::string toConvert);	// Verifica si es float
		static int		checkDouble(double convertedDouble, std::string toConvert);	// Verifica si es double

		static int		checkDigit(double convertedDouble, std::string toConvert);	// Verifica si es dígito válido
		static int		parse(std::string toConvert);								// Analiza el string y determina su tipo
		static int		pseudoLiterals(std::string toConvert);						// Verifica si es pseudoliteral (inf, nan, etc.)
		static int		single(std::string toConvert);								// Verifica si es un solo carácter
	public:
		// Función pública principal: convierte el string y muestra todas las conversiones
		static void	convert(std::string toConvert);

};
