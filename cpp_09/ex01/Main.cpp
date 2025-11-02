#include "RPN.hpp"
#include <iostream>

// Función principal: evalúa una expresión en notación polaca inversa (RPN)
// Uso: ./programa "expresión_rpn"
// Ejemplo: ./programa "8 9 * 9 - 9 - 9 - 4 - 1 +"
int main(int ac, char **av) {
    // Verifica que se haya proporcionado exactamente un argumento (la expresión RPN)
    if (ac != 2) {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return 1;
    }
	
	try {
		// Evalúa la expresión RPN proporcionada como argumento
		rpn(av[1]);
	}
	catch (const std::exception &e) {
		// Si hay un error en la expresión, imprime el mensaje de error
		std::cerr << "Error: " << e.what() << std::endl; 
		return 1;
	}
	return 0;
}
