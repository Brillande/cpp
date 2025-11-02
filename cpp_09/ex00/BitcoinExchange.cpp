#include "BitcoinExchange.hpp"

// ========== FTREGEX IMPLEMENTATION ==========
// Constructor: compila un patrón regex desde un string
FTregex::FTregex(const std::string &pattern)
{
    // Compila el patrón regex usando REG_EXTENDED (regex extendido POSIX)
    int status = regcomp(&_regex, pattern.c_str(), REG_EXTENDED);
    // Si la compilación falla, lanza una excepción con el código de error
    if (status)
        throw regex_err(status, _regex);
}

// Constructor: compila un patrón regex desde un char*
FTregex::FTregex(const char *pattern)
{
    // Compila el patrón regex usando REG_EXTENDED (regex extendido POSIX)
    int status = regcomp(&_regex, pattern, REG_EXTENDED);
    // Si la compilación falla, lanza una excepción con el código de error
    if (status)
        throw regex_err(status, _regex);
}

// Destructor: libera los recursos del regex compilado
FTregex::~FTregex()
{
    // Libera la memoria usada por el regex compilado
    regfree(&_regex);
}

// Ejecuta el patrón regex sobre un string de entrada y retorna los grupos capturados
FTregMatch FTregex::match(const std::string &input) const
{
    // Calcula el número de grupos (grupo 0 + grupos de captura)
    size_t                  nGroups = _regex.re_nsub + 1;
    // Vector para almacenar las posiciones de los grupos coincidentes
    std::vector<regmatch_t> pmatch(nGroups);
    // Vector para almacenar los strings de los grupos capturados
    FTregMatch              groups;

    // Ejecuta el regex sobre el string de entrada
    int status = regexec(&_regex, input.c_str(), nGroups, pmatch.data(), 0);
    // Si no coincide, lanza una excepción
    if (status != 0)
        throw regex_err(status, _regex);
    // Extrae los grupos capturados desde el string original
    for (size_t i = 0; i < nGroups; ++i)
    {
        // Si el grupo coincide (rm_so != -1), extrae el substring
        if (pmatch[i].rm_so != -1)
        {
            groups.push_back(input.substr(pmatch[i].rm_so,
                                          pmatch[i].rm_eo - pmatch[i].rm_so));
        }
        else
        {
            // Si el grupo no coincide, agrega string vacío
            groups.push_back("");
        }
    }
    return groups;
}

// Retorna el número de grupos de captura en el patrón (sin contar el grupo 0)
int FTregex::captureGroupSize(void) const
{
    return _regex.re_nsub;
}

// Constructor de regex_err: crea una excepción con un mensaje de error descriptivo
FTregex::regex_err::regex_err(int status, const regex_t &regex)
{
    // Buffer para almacenar el mensaje de error de POSIX
    char errorBuffer[256];
    // Obtiene el mensaje de error de POSIX y lo almacena en el buffer
    regerror(status, &regex, errorBuffer, sizeof(errorBuffer));
    // Crea el mensaje completo con prefijo identificador
    _msg = "FTregex compilation error: " + std::string(errorBuffer);
}

// Destructor de regex_err: libera recursos
FTregex::regex_err::~regex_err() throw() 
{

}

// Retorna el mensaje de error almacenado
const char *FTregex::regex_err::what() const throw()
{
    return _msg.c_str();
}

// ========== DATE IMPLEMENTATION ==========
// Tabla estática con los días máximos por mes (índice 0 no usado, 1-12 son los meses)
// Nota: febrero tiene 29 días (máximo en año bisiesto), se valida después
const uint32_t Date::_daysInMonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Tabla estática con los nombres de los meses en inglés (índice 0 vacío, 1-12 son los meses)
const std::string Date::_months[13] = {"",        "January",  "February", "March",  "April",
                                       "May",     "June",     "July",     "August", "September",
                                       "October", "November", "December"};

// Constructor por defecto: crea una fecha vacía (0) con separador por defecto
Date::Date() : _sep(DEFAULT_SEP)
{
    _date.raw = 0;
}

// Constructor: crea una fecha desde un string en formato YYYY-MM-DD
Date::Date(const std::string &date) : _sep(DEFAULT_SEP)
{ 
    // Valida y parsea la fecha usando el patrón por defecto
    _validDate(date, DEFAULT_DATE_PATTERN);
}

// Constructor: crea una fecha desde un string con un separador personalizado
Date::Date(const std::string &date, const std::string &sep) : _sep(sep)
{
    // Valida y parsea la fecha usando el patrón con el separador especificado
    _validDate(date, DATE_PATTERN(sep));
}

// Convierte la fecha a string en formato YYYY-MM-DD (con padding de ceros para mes y día)
std::string Date::toString() const
{
    std::ostringstream oss;
    // Formatea la fecha: año + separador + mes (2 dígitos con padding) + separador + día (2 dígitos con padding)
    oss << _date.year << _sep << std::setfill('0') << std::setw(2) << (uint32_t)_date.month << _sep
        << std::setfill('0') << std::setw(2) << (uint32_t)_date.day;
    return oss.str();
}

// Retorna el valor raw de la fecha (entero de 32 bits)
uint32_t Date::getRaw() const 
{
    return _date.raw;
}

// Verifica si un año es bisiesto
// Un año es bisiesto si: es divisible por 400, o (divisible por 4 y no divisible por 100)
static bool isLeapYear(unsigned year) 
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

// Valida y parsea una fecha desde un string usando un patrón regex
void Date::_validDate(const std::string &date, const std::string &pattern) 
{
    try 
    {
        // Crea un regex con el patrón especificado
        FTregex reg(pattern);
        // Verifica que el patrón capture exactamente 3 grupos (año, mes, día)
        if (reg.captureGroupSize() != 3)
            throw std::invalid_argument(DATE_INVALID_CAPTURE_GROUPS);

        // Ejecuta el regex sobre el string de fecha
        FTregMatch match = reg.match(date);

        // Convierte los grupos capturados a números enteros
        uint32_t year = strToType<uint32_t>(match[1]);
        uint32_t month = strToType<uint32_t>(match[2]);
        uint32_t day = strToType<uint32_t>(match[3]);

        // Almacena los valores en la estructura interna
        _date.year = year;
        _date.month = month;
        _date.day = day;

        // Valida el mes: debe estar entre 1 y 12
        if (month == 0 || month > 12)
            throw std::invalid_argument(DATE_INVALID_MONTH);
        // Valida el día: debe estar entre 1 y el máximo para ese mes
        if (day == 0 || day > _daysInMonth[month])
            throw std::invalid_argument(DATE_INVALID_DAY);
        // Validación especial para febrero en años no bisiestos (máximo 28 días)
        if (month == 2 && !isLeapYear(year) && day > 28)
            throw std::invalid_argument(DATE_INVALID_DAY);

    }
    catch (FTregex::regex_err &)
    {
        // Si el regex falla, lanza una excepción con mensaje de formato inválido
        throw std::invalid_argument(INVALID_DATE_PATTERN(date, _sep));
    }
}

// Obtiene el nombre del mes en el idioma localizado del sistema
std::string Date::_getLocalizedMonthName(unsigned month)
{
    // Valida que el mes esté en el rango válido (1-12)
    if (month < 1 || month > 12) 
    {
        throw std::out_of_range("Month must be in the range 1 to 12");
    }

	try 
    {
		// Intenta obtener el locale del sistema (idioma del sistema operativo)
		const std::locale &loc = std::locale("");

		// Crea un stringstream y configura el locale para usar el idioma del sistema
		std::ostringstream oss;
		oss.imbue(loc);
		// Crea una estructura de tiempo con el mes especificado
		std::tm timeStruct = {};
		timeStruct.tm_mon = month - 1;	// tm_mon usa 0-11, nuestro mes es 1-12
		timeStruct.tm_mday = 1;
		// Usa el facet time_put para obtener el nombre del mes en el idioma localizado
		std::use_facet<std::time_put<char> >(loc).put(oss, oss, ' ', &timeStruct, 'B');
		return oss.str();
	}
	catch (const std::runtime_error &e)
    {
		// Si falla (locale no disponible), retorna el nombre en inglés de la tabla estática
		return _months[month];
	}
}

// Genera un mensaje de error dinámico para días inválidos
inline std::string Date::_day_error_msg() 
{
    // Obtiene el máximo de días para el mes actual
    unsigned maxDays = _daysInMonth[_date.month];
    bool     leap = false;
    // Si es febrero y es año bisiesto, el máximo es 29 días
    if (_date.month == 2 && isLeapYear(_date.year)) 
    {
        maxDays = 29;
        leap = true;
    }

    // Genera el mensaje de error con el máximo de días permitido y el nombre del mes
    std::ostringstream oss;
    oss << "DATE: Invalid day: Days can only range from 1 to " << maxDays << " in "
        << _getLocalizedMonthName(_date.month)
		<< (leap ? " in a leap year." : ".");
    return oss.str();
}

// Operadores de comparación: comparan fechas usando el valor raw (entero de 32 bits)
// Como la fecha se almacena como YYYYMMDD en formato entero, las comparaciones son directas
bool Date::operator>(const Date &ref) const
{
    return _date.raw > ref._date.raw;
}
bool Date::operator<(const Date &ref) const
{
    return _date.raw < ref._date.raw;
}
bool Date::operator>=(const Date &ref) const
{
    return _date.raw >= ref._date.raw;
}
bool Date::operator<=(const Date &ref) const
{
    return _date.raw <= ref._date.raw;
}
bool Date::operator==(const Date &ref) const 
{
    return _date.raw == ref._date.raw;
}
bool Date::operator!=(const Date &ref) const 
{
    return _date.raw != ref._date.raw;
}

// Operador de salida: permite imprimir una fecha directamente con cout
std::ostream &operator<<(std::ostream &os, const Date &d) 
{
    os << d.toString();
    return os;
}

// ========== BITCOIN EXCHANGE IMPLEMENTATION ==========
// Constructor: carga automáticamente los datos desde data.csv
BitcoinExchange::BitcoinExchange() 
{
	// Carga los datos históricos de Bitcoin desde el archivo CSV por defecto
	addDataCsv(BTC_DATA);
}

// Carga datos de precios desde un archivo CSV
void BitcoinExchange::addDataCsv(const char *csv) 
{
    // Abre el archivo CSV
    std::ifstream data(csv);
    // Verifica que el archivo se haya abierto correctamente
    if (data.is_open() == false)
        throw std::runtime_error("BitcoinExchange : could not open the bitcoin data");

    // Crea un regex para parsear las líneas del CSV (formato: fecha,precio)
    FTregex     reg(FORMAT);
    std::string line;
    int         lineNumber = 2;	// Empieza en 2 porque la línea 1 es el header

    // Lee y valida el header (debe ser "date,exchange_rate")
    std::getline(data, line);
	if (line.empty() || line.compare("date,exchange_rate") != 0)
        throw std::runtime_error("BitcoinExchange : invalid data");

    // Lee cada línea del CSV y parsea los datos
    while (std::getline(data, line))
    {
        try
        {
                // Ejecuta el regex sobre la línea y extrae fecha y precio
                FTregMatch match = reg.match(line);
                // Crea un objeto Date desde el primer grupo (fecha)
                Date       date(match[1]);
                // Convierte el segundo grupo (precio) a float y lo almacena en el map
                _market[date] = strToType<float>(match[2]);

        } 
        catch (const std::exception &e) 
        {
            // Si hay un error al parsear una línea, lanza una excepción con el número de línea
            std::ostringstream oss;
            oss << "BitcoinExchange: error on line " << lineNumber << " [" << e.what() << "]";
            throw std::runtime_error(oss.str());
        }
        lineNumber++;
    }

	// Verifica que se haya cargado al menos un dato
	if (_market.empty())
        throw std::runtime_error("BitcoinExchange : no data Found");
}

// Obtiene el precio de Bitcoin para una fecha específica
float BitcoinExchange::getBtcPrice(const Date &date) 
{
    // Busca la fecha en el map usando lower_bound (busca la fecha >= date)
    Market::iterator it = _market.lower_bound(date);

    // Si hay una fecha anterior disponible, retrocede al iterador anterior
    // (lower_bound puede devolver una fecha mayor o end(), así que retrocedemos si es necesario)
    if (it != _market.begin() && (it == _market.end() || it->first > date)) 
    {
        --it;
    }

    // Si no hay datos para esa fecha o fechas anteriores, retorna 0
    if (it == _market.end() || it->first > date) 
    {
        return 0;
    }
    // Retorna el precio de la fecha encontrada (la fecha exacta o la anterior más cercana)
    return it->second;
}
