#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdint.h>
#include "PmergeMe.hpp"

// Función principal: ordena números usando el algoritmo merge-insert sort (Ford-Johnson)
// Compara el rendimiento entre std::vector y std::deque
// Uso: ./PmergeMe número1 número2 número3 ...
// Ejemplo: ./PmergeMe 3 5 9 7 4
int main(int ac, char **av) {
    // Verifica que se hayan proporcionado al menos un argumento (número)
    if (ac < 2) {
        std::cerr << "Error: No arguments provided" << std::endl;
        return 1;
    }

    try {
        // Ejecuta la implementación usando std::vector y mide su tiempo de ejecución
        // Nota: ++av avanza el puntero para saltar el nombre del programa
        pmergeme_vector(++av);
        // Ejecuta la implementación usando std::deque y mide su tiempo de ejecución
        pmergeme_deque(av);

    } catch (const std::exception &e) {
        // Si hay un error (entrada inválida, etc.), imprime el mensaje de error
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
