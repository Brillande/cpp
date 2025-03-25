/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:24:25 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 19:15:23 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


static int	open_fstreams(std::fstream& istream, std::fstream& ostream, char *fname)
{
	istream.open(fname, std::ios::in);
	ostream.open(strcat(fname, ".replace"), std::ios::out);
	
	if (!istream.is_open() || !ostream.is_open())
	{
		std::cout << "Error file not found" << std::endl;
		return (-1);
	}
	return (0);
}
//La referencia (&) significa que cualquier modificación hecha a line dentro de la función afectará directamente a la variable original pasada como argumento.
static void	replace(std::string& line, char *s1, char *s2)
{
	size_t begin;
	size_t len;
	
	begin = line.find(s1);
	len = strlen(s1);
	while (begin != std::string::npos)
	{
		line.replace(begin, len, s2);
		begin = line.find(s1, begin);
	}
}

int main(int argc, char **argv)
{
	std::fstream	istream;
	std::fstream	ostream;
	std::string 	line;
	char			*fname;
	char			*s1;
	char			*s2;
	
	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Invalid arguments" << std::endl;
		return (-1);
	}

	fname = argv[1];
	s1 = strdup(argv[2]);
	s2 = strdup(argv[3]);
/* 	Llama a la función open_fstreams, que intenta abrir dos flujos de archivo:
istream para leer el archivo de entrada (fname).
ostream para escribir en un archivo de salida con el nombre fname.replace.
Si no se pueden abrir ambos archivos, la función devuelve -1 y el programa termina con un mensaje de error. */
	if (open_fstreams(istream, ostream, fname))
		return (-1);
	while (getline(istream, line))
	{
		replace(line, s1, s2);
		ostream << line << std::endl;
	}
	istream.close();
	ostream.close();
}