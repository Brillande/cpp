/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:57:51 by emedina-          #+#    #+#             */
/*   Updated: 2025/04/30 14:57:52 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char	ScalarConverter::theChar = 'c';
int		ScalarConverter::theInt = -1;
float	ScalarConverter::theFloat = 0.0f;
double	ScalarConverter::theDouble = 0.0;

// Constructor privado: previene la instanciación de objetos
ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	if (this != &src)
    	*this = src;
	return ;
}

ScalarConverter &	ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}


// Función principal: convierte el string y muestra todas las conversiones posibles
void ScalarConverter::convert(std::string toConvert)
{
	// Analiza el string y determina qué tipo de dato es
    int whatIs = parse(toConvert);
	
	// Según el tipo detectado, llama a la función correspondiente para mostrar las conversiones
	switch(whatIs)
	{
		case 0:		
			isChar();
			break ;
		case 1:
			isPseudo();
			break ;

		case 2:
			isInt();
			break ;

		case 3:
			isFloat();
			break ;

		case 4:
			isDouble();
			break ;
		default:
			std::cout << "wrong input." << std::endl;
	}
	return ;
}

// Analiza el string y determina qué tipo de dato representa
int ScalarConverter::parse(std::string toConvert)
{
	int type = -1;
	
	// Si el string está vacío, retorna error
	if (toConvert.empty() == true)
		return (-1);
	
	// Verifica si es un solo carácter (char o dígito de un solo carácter)
	type = single(toConvert);
	if (toConvert.length() == 1 && ( type != -1))
		return (type);
	
	// Verifica si es un pseudoliteral (inf, -inf, nan, etc.)
	type = pseudoLiterals(toConvert);
	if (type == typePseudo)
		return (type);
	
	// Convierte el string en char* para usar strtod y convertirlo en double
	// strtod convierte un string a double, retornando HUGE_VAL en caso de overflow
	double	convertedDouble = strtod(toConvert.c_str(), NULL);

	// Si el resultado es infinito (overflow), retorna error
	if (convertedDouble == HUGE_VAL || convertedDouble == -HUGE_VAL)
		return (-1);
	
	// Verifica errores del sistema (rango, dominio, etc.)
	if (checkDigit(convertedDouble, toConvert) == 1 || errno == ERANGE || errno == EDOM || errno == EILSEQ)
		return (-1);
	
	// Verifica si el valor es válido
	type = checkDigit(convertedDouble, toConvert);
	if (type == 1 || errno == ERANGE || errno == EDOM || errno == EILSEQ)
		return (-1);
	
	// Intenta identificar el tipo en orden: int, float, double
	type = checkInt(convertedDouble, toConvert);
	if(type == typeInt)
		return (type);
	
	type = checkFloat(convertedDouble, toConvert);
	if (type == typeFloat)
		return (type);
	
	type = checkDouble(convertedDouble, toConvert);
	if (type == typeDouble)
		return (type);
	
	return (0);
}

// Verifica si el string es un solo carácter (char o dígito de un solo carácter)
int ScalarConverter::single(std::string toConvert)
{
	// Si es un dígito, lo convierte a int
	if (isdigit(*toConvert.c_str()))
	{
		theInt = atoi(toConvert.c_str());
		return (typeInt);
	}
	// Si es un carácter imprimible, lo guarda como char
	else if (isprint(*toConvert.c_str()))
	{
		theChar = toConvert[0];
		return (typeChar);
	}
	return (-1);
}

// Verifica si el string es un pseudoliteral (infinito o NaN)
int ScalarConverter::pseudoLiterals(std::string toConvert)
{
	// Arrays con los pseudoliterales válidos para float y double
	std::string	pseudoFloat[3] = 
	{
		"-inff", "+inff", "nanf"	// Valores especiales para float
	};
	std::string	pseudoDouble[3] = 
	{
		"-inf", "+inf", "nan"	// Valores especiales para double
	};
	int i;

	// Compara el string con todos los pseudoliterales posibles
	for (i = 0; i < 3; i++)	
	{
		// Si coincide con algún pseudoliteral float, sale del bucle
		if (toConvert.compare(pseudoFloat[i]) == 0)
			break ;
		// Si coincide con algún pseudoliteral double, sale del bucle
		if (toConvert.compare(pseudoDouble[i]) == 0)
			break ;
	}
	
	// Si encontró coincidencia, convierte y retorna tipo pseudoliteral
	if (i < 3)
	{
		theFloat = strtof(pseudoFloat[i].c_str(), NULL);
		theDouble = strtod(pseudoDouble[i].c_str(), NULL);
		return (typePseudo);
	}
	return (0);
}

// Verifica si el valor es un dígito simple sin punto decimal
int ScalarConverter::checkDigit(double convertedDouble, std::string toConvert)
{
	// std::string::npos es una constante que representa "no encontrado" (no position)
	// Si el valor dividido por 10 es 0 (solo un dígito) y no tiene punto decimal, es válido
	if (convertedDouble / 10 == 0 && toConvert.find('.') == std::string::npos)
		return (1);
	return (0);
}

// Verifica si el valor puede ser un int
int ScalarConverter::checkInt(double convertedDouble, std::string toConvert)
{
	// Si tiene punto decimal, no es un int
	if (toConvert.find('.') != std::string::npos)
		return (-1);
	
	// Si está fuera del rango de int, no es válido
	if (convertedDouble > INT_MAX || convertedDouble < INT_MIN)
		return (-1);
	
	// Convierte y guarda el valor como int
	theInt = static_cast<int>(convertedDouble);
	return (typeInt);
}

// Verifica si el valor puede ser un float
int ScalarConverter::checkFloat(double convertedDouble, std::string toConvert)
{
	// Un float debe tener punto decimal o sufijo 'f'
	if ((toConvert.find('.') == std::string::npos) && (toConvert.find('f') == std::string::npos))
		return (-1);

	// Cuenta cuántas veces aparece 'f' en el string
	int	i = 0, j = 0;
	while (toConvert[i] != 0)
	{
		if (toConvert[i] == 'f')
			j++;
		i++;
	}
	
	// Un float válido debe tener exactamente una 'f' al final
	if (j > 1 || toConvert[i - 1] != 'f')
		return (-1);
	
	// Comprueba si el valor absoluto es mayor que el máximo que puede almacenar un float
	if (abs(convertedDouble) > FLT_MAX)
		return (-1);
	
	// Convierte y guarda el valor como float
	theFloat = static_cast<float>(convertedDouble);
	return (typeFloat);
}

// Verifica si el valor puede ser un double
int ScalarConverter::checkDouble(double convertedDouble, std::string toConvert)
{
	// Un double no debe tener sufijo 'f' (ese sería float)
	if (toConvert.find('f') != std::string::npos)
		return (1);
	
	// Convierte y guarda el valor como double
	theDouble = static_cast<double>(convertedDouble);
	return (typeDouble);
}

// Muestra la conversión cuando la entrada es un char
void ScalarConverter::isChar()
{
	// Convierte el char a los otros tipos
	theInt =  static_cast<int>(theChar);
	theFloat =  static_cast<float>(theChar);
	theDouble =  static_cast<double>(theChar);

	// Imprime todas las conversiones
	std::cout << "Char: '" << theChar << "'" << std::endl;
	std::cout << "Int: " << theInt << std::endl;
	// std::setprecision(1): muestra solo una cifra decimal
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;

	return ;
}

// Muestra la conversión cuando la entrada es un pseudoliteral (inf, nan, etc.)
void ScalarConverter::isPseudo()
{
	// Los pseudoliterales no pueden convertirse a char ni int
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	// Solo se pueden mostrar como float y double
	std::cout << "Float: " << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;
	return ;
}

// Muestra la conversión cuando la entrada es un int
void ScalarConverter::isInt()
{
	// Verifica si el int se puede convertir a char imprimible (ASCII 32-126)
	if (theInt <= 126 && theInt >= 32)
	{
		theChar =  static_cast<char>(theInt);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	// Si es un carácter no imprimible (0-31 o 127)
	else if ((theInt >= 0 && theInt <= 31) || theInt == 127)
		std::cout << "Char: Non displayable" << std::endl;
	// Si está fuera del rango de char (negativo o > 127)
	else
		std::cout << "Char: impossible" << std::endl;

	// Convierte a float y double (siempre es posible)
	theFloat =  static_cast<float>(theInt);
	theDouble =  static_cast<double>(theInt);

	std::cout << "Int: " << theInt << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;

	return ;
}

// Muestra la conversión cuando la entrada es un float
void ScalarConverter::isFloat()
{
	// Verifica si el float se puede convertir a char imprimible (ASCII 32-126)
	if (theFloat <= 126 && theFloat >= 32)
	{
		theChar =  static_cast<char>(theFloat);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	// Si es un carácter no imprimible (0-31 o 127)
	else if ((theFloat >= 0 && theFloat <= 31) || theFloat == 127)
		std::cout << "Char: Non displayable" << std::endl;
	// Si está fuera del rango de char
	else
		std::cout << "Char: impossible" << std::endl;
	
	// Verifica si el float está dentro del rango de int (INT_MAX = 2147483647, INT_MIN = -2147483648)
	if (theFloat > 2147483647.0 || theFloat < -2147483648.0)
		std::cout << "Int: impossible" << std::endl;
	else
	{
		theInt =  static_cast<int>(theFloat);
		std::cout << "Int: " << theInt << std::endl;
	}
	
	// Convierte a double (siempre es posible desde float)
	theDouble =  static_cast<double>(theFloat);
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;

	return ;
}


// Muestra la conversión cuando la entrada es un double
void ScalarConverter::isDouble()
{
	// Verifica si el double se puede convertir a char imprimible (ASCII 32-126)
	if (theDouble <= 126 && theDouble >= 32)
	{
		theChar =  static_cast<char>(theDouble);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	// Si es un carácter no imprimible (0-31 o 127)
	else if ((theDouble >= 0 && theDouble <= 31) || theDouble == 127)
		std::cout << "Char: Non displayable" << std::endl;
	// Si está fuera del rango de char
	else
		std::cout << "Char: impossible" << std::endl;
	
	// Verifica si el double está dentro del rango de int
	if (theDouble > 2147483647.0 || theDouble < -2147483648.0)
		std::cout << "Int: impossible" << std::endl;
	else
	{
		theInt =  static_cast<int>(theDouble);
		std::cout << "Int: " << theInt << std::endl;
	}
	
	// Verifica si el double cabe en un float (si es mayor que FLT_MAX, será infinito)
	if (abs(theDouble) > FLT_MAX)
		std::cout << "Float: " << "inf"<< std::endl;
	else
	{
		theFloat =  static_cast<float>(theDouble);
		std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	}
	std::cout << "Double: " << theDouble << std::endl;
	return ;
}
