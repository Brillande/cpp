#pragma once

// Función para evaluar una expresión en notación polaca inversa (RPN)
// La expresión debe estar en formato string con operadores y operandos separados por espacios
// Operadores soportados: + (suma), - (resta), * (multiplicación), / (división)
// Lanza std::runtime_error si hay un error en la expresión o formato inválido
void rpn(const char *str);
