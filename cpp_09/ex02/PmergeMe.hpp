#pragma once

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <deque>
#include <sys/time.h>

// Tipos definidos para facilitar el uso de pares de enteros sin signo de 32 bits
typedef std::vector<std::pair<uint32_t, uint32_t> > pair_vector_u32_t;	// Vector de pares para implementación con vector
typedef std::deque<std::pair<uint32_t, uint32_t> > pair_deque_u32_t;		// Deque de pares para implementación con deque

// Macro para medir el tiempo de ejecución de un bloque de código
// time_value: variable donde se guardará el tiempo en microsegundos
// routine: bloque de código a medir
#define TIME(time_value, routine)                                                                  \
    double time_value = 0;                                                                         \
    {                                                                                              \
        struct timeval start, end;                                                                \
        gettimeofday(&start, NULL);		/* Obtiene el tiempo antes de ejecutar */               \
        routine						/* Ejecuta el bloque de código a medir */               \
        gettimeofday(&end, NULL);		/* Obtiene el tiempo después de ejecutar */             \
        time_value = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);  /* Calcula diferencia en microsegundos */            \
    }

// Crea una lista de enteros sin signo desde un array de strings
std::vector<uint32_t> create_list(char **str);

// Imprime los resultados comparando tiempos de ejecución entre vector y deque
void print_res(const std::vector<uint32_t> &start,
				const std::vector<uint32_t> &res,
				double vector_time,
				double deque_time);

// Implementación del algoritmo merge-insert sort usando vector
void pmergeme_vector(char **str);

// Implementación del algoritmo merge-insert sort usando deque
void pmergeme_deque(char **str);

// Funciones auxiliares para la implementación con deque
void init_merge_pair_deque(const std::vector<uint32_t> &input, pair_deque_u32_t &res_deque, bool &odd_pair);	// Inicializa pares para merge sort
void merge_sort_pair_deque(pair_deque_u32_t &vec, size_t left, size_t right);	// Ordena pares usando merge sort recursivo
void insertion_deque(std::deque<uint32_t> &arr, uint32_t value);	// Inserta un valor en orden usando inserción binaria
void print_res_deque(const std::vector<uint32_t> &start, const std::deque<uint32_t> &res, double merge_time, double insert_time);	// Imprime resultados para deque
