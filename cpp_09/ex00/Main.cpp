#include "BitcoinExchange.hpp"
#include <fstream>

// Patrón regex para parsear líneas del archivo de wallet del usuario
// Formato esperado: fecha | cantidad (ejemplo: "2024-01-01 | 1.5")
// Captura grupo 1: fecha, grupo 2: cantidad (número con signo opcional y decimales opcionales)
#define WALLET_FORMAT "^([^|]*) \\| ([-+]?[0-9]+(\\.[0-9]+)?)\n?$"

// Procesa una línea del archivo de wallet del usuario
// Calcula el valor total en dólares de la cantidad de Bitcoin para una fecha específica
static void compute_line(const std::string &line, BitcoinExchange &market,
                         const FTregex &reg) 
{
    try
    {
        // Ejecuta el regex sobre la línea y extrae fecha y cantidad
        FTregMatch matches = reg.match(line);
        // Crea un objeto Date desde el primer grupo (fecha)
        Date       date(matches[1]);
        // Obtiene el precio de Bitcoin para esa fecha (precio histórico más cercano)
        float      price = market.getBtcPrice(date);

        // Convierte el segundo grupo (cantidad de Bitcoin) a float
        float btc = strToType<float>(matches[2]);
        // Valida que la cantidad sea positiva (no negativa)
        if (btc < 0)
            throw std::runtime_error("not a positive number.");
        // Valida que la cantidad no exceda 1000
        if (btc > 1000)
            throw std::runtime_error("too large a number.");
        // Imprime el resultado: fecha => cantidad_bitcoin = valor_total_dolares
        std::cerr << date << " => " << btc << " = " << btc * price << std::endl;

    }
    catch (const std::exception &e)
    {
        // Si hay un error, imprime el error junto con la línea que causó el problema
        std::cerr << "Error: " << e.what() << " [" << line << "]" << std::endl;
    }
}

// Función principal: calcula el valor de Bitcoin en dólares para fechas específicas
int main(int ac, char **av)
{
    // Verifica que se haya proporcionado exactamente un argumento (archivo de wallet)
    if (ac != 2)
	{
		std::cerr << "Wrong arg" << std::endl; 
		return (1);
	}

    try
    {
        // Crea una instancia de BitcoinExchange (carga automáticamente data.csv)
        BitcoinExchange market;

        // Abre el archivo de wallet del usuario
        std::ifstream data(av[1]);
        if (data.is_open() == false)
            throw std::runtime_error("User data : could not open the user wallet file");

        // Crea un regex para parsear las líneas del archivo de wallet
        FTregex     reg(WALLET_FORMAT);
        std::string line;
        // Procesa cada línea del archivo
        while (std::getline(data, line))
            compute_line(line, market, reg);
    }
    catch (const std::exception &e)
    {
        // Si hay un error crítico (archivo no existe, etc.), imprime el error
        std::cout << e.what() << std::endl;
    }
}
