#include "RPN.hpp"
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <stdint.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <climits>

// Funciones auxiliares para realizar operaciones aritméticas con validación de overflow

// Suma: retorna nb1 + nb2
// Lanza std::runtime_error si hay overflow
static int rpn_add(int nb1, int nb2) {
    // Verificar overflow en suma: a + b > INT_MAX o a + b < INT_MIN
    if (nb1 > 0 && nb2 > INT_MAX - nb1)
        throw std::runtime_error("integer overflow in addition");
    if (nb1 < 0 && nb2 < INT_MIN - nb1)
        throw std::runtime_error("integer overflow in addition");
    return nb1 + nb2;
}

// Resta: retorna nb1 - nb2
// Lanza std::runtime_error si hay overflow
static int rpn_sub(int nb1, int nb2) {
    // Verificar overflow en resta: a - b > INT_MAX o a - b < INT_MIN
    // a - b > INT_MAX es equivalente a a > INT_MAX + b
    // a - b < INT_MIN es equivalente a a < INT_MIN + b
    if (nb2 < 0 && nb1 > INT_MAX + nb2)
        throw std::runtime_error("integer overflow in subtraction");
    if (nb2 > 0 && nb1 < INT_MIN + nb2)
        throw std::runtime_error("integer overflow in subtraction");
    return nb1 - nb2;
}

// Multiplicación: retorna nb1 * nb2
// Lanza std::runtime_error si hay overflow
static int rpn_mult(int nb1, int nb2) {
    // Verificar overflow en multiplicación
    // Caso especial: si alguno es 0, no hay overflow
    if (nb1 == 0 || nb2 == 0)
        return 0;
    
    // Verificar si nb1 * nb2 > INT_MAX
    // Esto es equivalente a nb1 > INT_MAX / nb2 (si nb2 > 0)
    // o nb1 < INT_MAX / nb2 (si nb2 < 0)
    if (nb1 > 0 && nb2 > 0) {
        if (nb1 > INT_MAX / nb2)
            throw std::runtime_error("integer overflow in multiplication");
    } else if (nb1 < 0 && nb2 < 0) {
        // Ambos negativos: resultado positivo
        if (nb1 < INT_MAX / nb2)  // nb2 es negativo, así que INT_MAX / nb2 es negativo
            throw std::runtime_error("integer overflow in multiplication");
    } else {
        // Uno positivo y uno negativo: resultado negativo
        // Verificar si nb1 * nb2 < INT_MIN
        if (nb1 > 0) {
            if (nb1 > INT_MIN / nb2)  // nb2 es negativo
                throw std::runtime_error("integer overflow in multiplication");
        } else {
            if (nb2 > INT_MIN / nb1)  // nb1 es negativo
                throw std::runtime_error("integer overflow in multiplication");
        }
    }
    return nb1 * nb2;
}

// División: retorna nb1 / nb2
// Lanza std::runtime_error si nb2 == 0 (división por cero)
// Nota: La división de enteros en C++ trunca hacia cero, no hay overflow en división
static int rpn_div(int nb1, int nb2) {
    if (nb2 == 0)
        throw std::runtime_error("you can't do a division by 0");
    return nb1 / nb2;
}


// Ejecuta una operación binaria (suma, resta, multiplicación o división)
// str: puntero al operador actual (se incrementa después de la operación)
// stack: pila que contiene los operandos
// sign: puntero a función que realiza la operación (rpn_add, rpn_sub, rpn_mult, rpn_div)
static void rpn_sign(const char *&str, std::stack<int> &stack, int sign(int, int)) {
    int a, b;

    // Verifica que haya al menos 2 números en la pila para realizar la operación
    if (stack.size() < 2)
        throw std::runtime_error("you can't do a action on less than 2 number");
    // Extrae los dos operandos de la pila (el orden es importante para resta y división)
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    // Ejecuta la operación y coloca el resultado en la pila
    stack.push(sign(a, b));
    // Avanza al siguiente carácter
    str++;
    // Verifica que después del operador haya un espacio o el final del string
    if (*str != ' ' && *str != 0)
        throw std::runtime_error("invalid formating");
}

// Obtiene el ancho de la terminal en caracteres
// Si no se puede obtener, retorna 80 (ancho por defecto)
static int get_term_width() {
    struct winsize w;
    // Intenta obtener el tamaño de la terminal usando ioctl
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    } else {
        return 80; // Ancho por defecto si no se puede obtener
    }
}

// Crea un mensaje de error formateado con el ancho máximo de la terminal
// msg: mensaje de error original
// start: inicio del string original (expresión completa)
// error_index: índice donde ocurrió el error en el string
static std::string rpn_error(const char *msg, const char *start, size_t error_index) {
    // Obtiene el ancho de la terminal
    size_t term_size = get_term_width();

    std::string str(start);

    // Calcula el índice donde recortar el string para mostrarlo en el ancho de la terminal
    // Alinea a múltiplos del ancho de la terminal para mejor formato
	size_t trim_index = (error_index + term_size - 1) & ~(term_size - 1);
    // Asegura que no se exceda el tamaño del string
    if (trim_index > str.size())
        trim_index = str.size();
    // Recorta el string hasta el índice calculado
    std::string tri_str_start = str.substr(0, trim_index);
    // Crea un string con espacios para posicionar el indicador de error (^)
    std::string space_index(error_index, ' ');

    // Genera el mensaje de error formateado: mensaje + string recortado + indicador de posición
    std::ostringstream o;
    o << msg << "\n\n" << tri_str_start << "\n" << space_index << "^";

    return o.str();
}

// Procesa un carácter de la expresión RPN (número u operador)
// index: puntero al carácter actual (se modifica si se procesa un número)
// stack: pila que contiene los operandos
// Nota: se usa if-else en lugar de unordered_map porque no está permitido en el estándar C++98
static void _action(const char *&index, std::stack<int> &stack) {
    // CAMBIO: Solo acepta un único dígito (0-9), no permite números de múltiples dígitos
    // Si es un dígito, lo convierte a entero y lo coloca en la pila
    if (isdigit(*index)) {
        int num = *index - '0';  // Convierte el carácter dígito a entero (0-9)
        index++;  // Avanza al siguiente carácter
        
        // CAMBIO: Verifica que después del dígito haya un espacio o el final del string
        // Si hay otro dígito consecutivo, lanza un error (no permite números de múltiples dígitos)
        if (isdigit(*index)) {
            throw std::runtime_error("only single digits (0-9) are allowed");
        }
        
        // Coloca el número en la pila
        stack.push(num);
        return; // Retorna sin incrementar index (ya se incrementó arriba)
    }

    // Procesa operadores binarios
    else if (*index == '*')
        rpn_sign(index, stack, rpn_mult);
    else if (*index == '/')
        rpn_sign(index, stack, rpn_div);
    else if (*index == '+')
        rpn_sign(index, stack, rpn_add);
    else if (*index == '-')
        rpn_sign(index, stack, rpn_sub);
    // Modulo no está soportado
    else if (*index == '%')
        throw std::runtime_error("modulo operator not supported");
    // Los espacios se ignoran (no hacen nada)
    else if (*index == ' ')
        return; // ' ' no hace nada
    // Cualquier otro carácter es inválido
    else
        throw std::runtime_error("invalid formating");
}

// Evalúa una expresión en notación polaca inversa (RPN)
// str: string que contiene la expresión RPN (operadores y operandos separados por espacios)
// Ejemplo: "8 9 * 9 - 9 - 9 - 4 - 1 +" -> 42
void rpn(const char *str) {
    const char     *index = str;	// Puntero que recorre el string
    std::stack<int> stack;			// Pila para almacenar operandos y resultados intermedios

    // Procesa cada carácter del string
    while (*index) {
        // Ignora espacios consecutivos al inicio
        while (*index == ' ') {
            index++;
        }
        // Si se llegó al final del string, termina
        if (!*index) break;
        
        try {
            // Procesa el carácter actual (número u operador)
            _action(index, stack);
        } catch (std::exception &e) {
            // Si hay un error, genera un mensaje formateado con la posición del error
            throw std::runtime_error(rpn_error(e.what(), str, index - str));
        }
    }
    // Al final, debe haber exactamente un valor en la pila (el resultado)
    if (stack.size() != 1)
        throw std::runtime_error("invalid formating");
    
    // Imprime el resultado
    std::cout << "Result: " << stack.top() << std::endl;
}
