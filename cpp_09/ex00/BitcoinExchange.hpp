#pragma once

#include <regex.h>
#include <fstream>
#include <stdexcept>
#include <map>
#include <stdint.h>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <locale>

// Patrón regex para parsear líneas del CSV de Bitcoin (formato: fecha,precio)
// Captura grupo 1: fecha, grupo 2: precio (número con decimales opcionales)
#define FORMAT "^([^|]*),([0-9]+(\\.[0-9]+)?)\n?$"

// Archivo CSV que contiene los datos históricos de Bitcoin
#define BTC_DATA "data.csv"

// Separador por defecto para fechas (formato: YYYY-MM-DD)
#ifndef DEFAULT_SEP
#define DEFAULT_SEP "-"
#endif

// Genera un patrón regex para fechas con un separador específico
// Formato: YYYY{sep}MM{sep}DD (ejemplo: YYYY-MM-DD)
#define DATE_PATTERN(sep) "^([0-9]+)" + sep + "([0-9]{2})" + sep + "([0-9]{2})$"

// Patrón de fecha por defecto usando el separador DEFAULT_SEP
#define DEFAULT_DATE_PATTERN DATE_PATTERN(std::string(DEFAULT_SEP))

// Genera un mensaje de error cuando el formato de fecha es inválido
#define INVALID_DATE_PATTERN(userInput, sep) \
    "DATE: Invalid date format: expected 'YYYY" + sep + "MM" + sep + "DD', but got '" + userInput + "'."

// Mensaje de error cuando el patrón regex no captura 3 grupos
#define DATE_INVALID_CAPTURE_GROUPS \
    "DATE: Invalid pattern capture Groups: The pattern should have 3 capture Groups."

// Mensaje de error cuando el mes está fuera del rango válido (1-12)
#define DATE_INVALID_MONTH "DATE: Invalid month : Months can only range from 1 to 12."

// Mensaje de error para días inválidos (se genera dinámicamente)
#define DATE_INVALID_DAY _day_error_msg()

// Template para convertir string a tipo numérico
template <typename T> T strToType(const std::string &str)
{
  std::stringstream ss(str);
  T result;
  ss >> result;
  return result;
}

// ========== FTREGEX ==========
// Clase wrapper para regex.h (POSIX regex) que proporciona una interfaz más fácil de usar
// FTregMatch: vector de strings que contiene los grupos capturados por el regex
typedef std::vector<std::string> FTregMatch;
typedef FTregMatch::iterator FTregMatchIt;

// Clase para trabajar con expresiones regulares usando regex.h (POSIX)
// Permite compilar y ejecutar patrones regex, capturando grupos de forma sencilla
class FTregex 
{
  public:
    // Constructor: compila un patrón regex desde un string
    FTregex(const std::string &pattern);
    // Constructor: compila un patrón regex desde un char*
    FTregex(const char *pattern);
    // Destructor: libera los recursos del regex compilado
    ~FTregex();

    // Ejecuta el patrón regex sobre un string de entrada y retorna los grupos capturados
    // Lanza regex_err si el patrón no coincide
    FTregMatch match(const std::string &input) const;
	// Retorna el número de grupos de captura en el patrón (sin contar el grupo 0)
	int captureGroupSize(void) const;

    // Excepción personalizada para errores de regex
    class regex_err : public std::exception 
    {
      public:
        // Constructor: crea una excepción con el código de error y el regex
        regex_err(int status, const regex_t &regex);
		// Destructor virtual
		virtual ~regex_err() throw();
        // Retorna el mensaje de error descriptivo
        virtual const char *what() const throw();
      private:
        std::string _msg;	// Mensaje de error almacenado
    };
  private:
    regex_t _regex;	// Estructura POSIX regex compilada
};

// ========== DATE ==========
// Clase para representar y manipular fechas con validación
// Almacena la fecha de forma compacta usando un union (32 bits total)
class Date 
{
  public:
    // Constructor por defecto: crea una fecha vacía (0)
    Date();
    // Constructor: crea una fecha desde un string en formato YYYY-MM-DD
    Date(const std::string &date);
    // Constructor: crea una fecha desde un string con un separador personalizado
    Date(const std::string &date, const std::string &sep);

    // Convierte la fecha a string en formato YYYY-MM-DD (con padding de ceros)
    std::string toString(void) const;
    // Retorna el valor raw de la fecha (entero de 32 bits)
    uint32_t    getRaw() const;

    // Operadores de comparación: comparan fechas usando el valor raw
    bool operator>(const Date &) const;	// Mayor que
    bool operator<(const Date &) const;	// Menor que
    bool operator>=(const Date &) const;	// Mayor o igual que
    bool operator<=(const Date &) const;	// Menor o igual que
    bool operator==(const Date &) const;	// Igual que
    bool operator!=(const Date &) const;	// Diferente que

  private:
    // Valida y parsea una fecha desde un string usando un patrón regex
    void               _validDate(const std::string &date, const std::string &pattern);
    // Obtiene el nombre del mes en el idioma localizado del sistema
    std::string        _getLocalizedMonthName(unsigned month);
    // Genera un mensaje de error dinámico para días inválidos
    inline std::string _day_error_msg();

    // Union para almacenar la fecha de forma compacta (32 bits)
    // Permite acceso tanto como entero (raw) como estructura (day, month, year)
    union 
    {
        uint32_t raw;	// Fecha completa como entero sin signo de 32 bits
        struct 
        {
            uint8_t  day;	// Día (1-31)
            uint8_t  month;	// Mes (1-12)
            uint16_t year;	// Año (0-65535)
        };
    } _date;
    const std::string _sep;	// Separador usado en el formato (por defecto "-")

    // Tabla estática con los días máximos por mes (índice 0 no usado, 1-12 son los meses)
    static const uint32_t    _daysInMonth[13];
    // Tabla estática con los nombres de los meses en inglés (índice 0 vacío, 1-12 son los meses)
    static const std::string _months[13];
};

// Operador de salida: permite imprimir una fecha directamente con cout
std::ostream &operator<<(std::ostream &os, const Date &d);

// ========== BITCOIN EXCHANGE ==========
// Map que asocia fechas con precios de Bitcoin (dobles)
// Las fechas se ordenan automáticamente y permiten búsqueda eficiente
typedef std::map<Date, double> Market;

// Clase principal para gestionar el intercambio de Bitcoin
// Carga datos históricos de precios desde un CSV y permite consultar precios por fecha
class BitcoinExchange 
{
  public:
    // Constructor: carga automáticamente los datos desde data.csv
    BitcoinExchange(void);
	// Obtiene el precio de Bitcoin para una fecha específica
	// Si no existe la fecha exacta, retorna el precio de la fecha anterior más cercana
	// Retorna 0 si no hay datos para esa fecha o fechas anteriores
	float getBtcPrice(const Date &date);
	// Carga datos de precios desde un archivo CSV
	// El formato esperado es: fecha,precio (primera línea debe ser: date,exchange_rate)
	void addDataCsv(const char *csv);

  private:
	Market _market;	// Map que almacena los precios históricos de Bitcoin por fecha
};
