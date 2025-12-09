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
        // Avanza el puntero para saltar el nombre del programa
        // Guarda una copia del puntero original para que ambas funciones puedan procesar los mismos argumentos
        char **args = ++av;
        // Crea una copia del array de argumentos para que no se modifique el original
        // Esto es necesario porque create_list modifica el puntero que recibe
        int arg_count = ac - 1;
        char **args_copy = new char*[arg_count + 1];
        for (int i = 0; i < arg_count; i++) {
            args_copy[i] = args[i];
        }
        args_copy[arg_count] = NULL;
        
        // Ejecuta la implementación usando std::vector y mide su tiempo de ejecución
        pmergeme_vector(args_copy);
        
        // Restaura el puntero para la segunda llamada
        for (int i = 0; i < arg_count; i++) {
            args_copy[i] = args[i];
        }
        args_copy[arg_count] = NULL;
        
        // Ejecuta la implementación usando std::deque y mide su tiempo de ejecución
        pmergeme_deque(args_copy);
        
        delete[] args_copy;

    } catch (const std::exception &e) {
        // Si hay un error (entrada inválida, etc.), imprime el mensaje de error
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
