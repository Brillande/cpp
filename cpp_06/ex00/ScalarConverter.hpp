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

#define typeChar 0
#define typePseudo 1
#define typeInt 2
#define typeFloat 3
#define typeDouble 4

class ScalarConverter
{
	private:
		static char		theChar;
		static int		theInt;
		static float	theFloat;
		static double	theDouble;
        ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter&	operator=(ScalarConverter const &assign);
		~ScalarConverter(void);
        static void		isChar(void);
		static void		isInt(void);
		static void		isFloat(void);
		static void		isDouble(void);
        static void		isPseudo(void);

        static int		checkInt(double convertedDouble, std::string toConvert);	
		static int		checkFloat(double convertedDouble, std::string toConvert);
		static int		checkDouble(double convertedDouble, std::string toConvert);

		static int		checkDigit(double convertedDouble, std::string toConvert);
		static int		parse(std::string toConvert);
		static int		pseudoLiterals(std::string toConvert);
		static int		single(std::string toConvert);
	public:
		static void	convert(std::string toConvert);

};
