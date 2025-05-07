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


void ScalarConverter::convert(std::string toConvert)
{
	
    int whatIs = parse(toConvert);
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

int ScalarConverter::parse(std::string toConvert)
{
	int type = -1;
	if (toConvert.empty() == true)
		return (-1);
	type = single(toConvert);
	if (toConvert.length() == 1 && ( type != -1))
		return (type);
	type = pseudoLiterals(toConvert);
	if (type == typePseudo)
		return (type);
	//convierte el string en char * para usar strtod y convertirlo en double
	double	convertedDouble = strtod(toConvert.c_str(), NULL);

	if (convertedDouble == HUGE_VAL || convertedDouble == -HUGE_VAL)
		return (-1);
	if (checkDigit(convertedDouble, toConvert) == 1 || errno == ERANGE || errno == EDOM || errno == EILSEQ)
		return (-1);
	type = checkDigit(convertedDouble, toConvert);
	if (type == 1 || errno == ERANGE || errno == EDOM || errno == EILSEQ)
		return (-1);
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

int ScalarConverter::single(std::string toConvert)
{
	if (isdigit(*toConvert.c_str()))
	{
		theInt = atoi(toConvert.c_str());
		return (typeInt);
	}
	else if (isprint(*toConvert.c_str()))
	{
		theChar = toConvert[0];
		return (typeChar);
	}
	return (-1);
}

int ScalarConverter::pseudoLiterals(std::string toConvert)
{
	std::string	pseudoFloat[3] = 
	{
		"-inff", "+inff", "nanf"
	};
	std::string	pseudoDouble[3] = 
	{
		"-inf", "+inf", "nan"
	};
	int i;

	for (i = 0; i < 3; i++)	
	{
		if (toConvert.compare(pseudoFloat[i]) == 0)
			break ;
		if (toConvert.compare(pseudoDouble[i]) == 0)
			break ;
	}
	if (i < 3)
	{
		theFloat = strtof(pseudoFloat[i].c_str(), NULL);
		theDouble = strtod(pseudoDouble[i].c_str(), NULL);
		return (typePseudo);
	}
	return (0);
}

int ScalarConverter::checkDigit(double convertedDouble, std::string toConvert)
{
	//std::string::npos es una constante especial de la clase std::string en C++ que representa "no encontrado" (no position).
	if (convertedDouble / 10 == 0 && toConvert.find('.') == std::string::npos)
		return (1);
	return (0);
}

int ScalarConverter::checkInt(double convertedDouble, std::string toConvert)
{
	if (toConvert.find('.') != std::string::npos)
		return (-1);
	if (convertedDouble > INT_MAX || convertedDouble < INT_MIN)
		return (-1);
	theInt = static_cast<int>(convertedDouble);
	return (typeInt);
}

int ScalarConverter::checkFloat(double convertedDouble, std::string toConvert)
{
	if ((toConvert.find('.') == std::string::npos) && (toConvert.find('f') == std::string::npos))
		return (-1);

	int	i = 0, j = 0;

	while (toConvert[i] != 0)
	{
		if (toConvert[i] == 'f')
			j++;
		i++;
	}
	if (j > 1 || toConvert[i - 1] != 'f')
		return (-1);
	// comprueba si el valor absoluto de convertedDouble es mayor que el valor máximo que puede almacenar un float
	if (abs(convertedDouble) > FLT_MAX)
		return (-1);
	theFloat = static_cast<float>(convertedDouble);
	return (typeFloat);
}

int ScalarConverter::checkDouble(double convertedDouble, std::string toConvert)
{
	if (toConvert.find('f') != std::string::npos)
		return (1);
	theDouble = static_cast<double>(convertedDouble);
	return (typeDouble);
}

void ScalarConverter::isChar()
{
	theInt =  static_cast<int>(theChar);
	theFloat =  static_cast<float>(theChar);
	theDouble =  static_cast<double>(theChar);

	std::cout << "Char: '" << theChar << "'" << std::endl;
	std::cout << "Int: " << theInt << std::endl;
	//std::setprecision(1): muestra solo una cifra decimal.
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;

	return ;
}

void ScalarConverter::isPseudo()
{
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "Int: " << "impossible" << std::endl;
	std::cout << "Float: " << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;
	return ;
}

void ScalarConverter::isInt()
{
	if (theInt <= 126 && theInt >= 32)
	{
		theChar =  static_cast<char>(theInt);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	else if ((theInt >= 0 && theInt <= 31) || theInt == 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;

	theFloat =  static_cast<float>(theInt);
	theDouble =  static_cast<double>(theInt);

	std::cout << "Int: " << theInt << std::endl;
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;

	return ;
}

void ScalarConverter::isFloat()
{
	if (theFloat <= 126 && theFloat >= 32)
	{
		theChar =  static_cast<char>(theFloat);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	else if ((theFloat >= 0 && theFloat <= 31) || theFloat == 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;
	if (theFloat > 2147483647.0 || theFloat < -2147483648.0)
		std::cout << "Int: impossible" << std::endl;
	else
	{
		theInt =  static_cast<int>(theFloat);
		std::cout << "Int: " << theInt << std::endl;
	}
	theDouble =  static_cast<double>(theFloat);
	std::cout << "Float: " << std::fixed << std::setprecision(1) << theFloat << "f" << std::endl;
	std::cout << "Double: " << theDouble << std::endl;

	return ;
}


void ScalarConverter::isDouble()
{
	if (theDouble <= 126 && theDouble >= 32)
	{
		theChar =  static_cast<char>(theDouble);
		std::cout << "Char: '" << theChar << "'" << std::endl;
	}
	else if ((theDouble >= 0 && theDouble <= 31) || theDouble == 127)
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: impossible" << std::endl;
	if (theDouble > 2147483647.0 || theDouble < -2147483648.0)
		std::cout << "Int: impossible" << std::endl;
	else
	{
		theInt =  static_cast<int>(theDouble);
		std::cout << "Int: " << theInt << std::endl;
	}
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
