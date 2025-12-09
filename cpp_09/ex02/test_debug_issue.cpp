#include <iostream>
#include <cstring>

int main() {
    char *args[] = {(char *)"5", (char *)"3", (char *)"2", NULL};
    char **av = args;
    
    std::cout << "Antes:" << std::endl;
    for (int i = 0; av[i]; i++) {
        std::cout << "  av[" << i << "] = \"" << av[i] << "\"" << std::endl;
    }
    
    // Simular lo que hace create_list
    char **str = av;
    while (*str) {
        char *original = *str;
        // Simular getNextNumber que modifica *str
        // En getNextNumber, se hace *str = endptr, lo que modifica el puntero
        std::cout << "Procesando: \"" << *str << "\"" << std::endl;
        // Si getNextNumber avanza el puntero dentro del string, esto podría ser un problema
        str++;
    }
    
    std::cout << "Después:" << std::endl;
    for (int i = 0; args[i]; i++) {
        std::cout << "  args[" << i << "] = \"" << args[i] << "\"" << std::endl;
    }
    
    return 0;
}
