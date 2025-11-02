#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <stdint.h>
#include <vector>
#include <deque>

// ========== FUNCIONES DE PARSING ==========

// Parsea el siguiente número desde el string
// Retorna -1 si no se encuentra ningún número
// Lanza std::runtime_error para entrada inválida
static int64_t getNextNumber(char **str) {
    // Ignora espacios en blanco al inicio
    while (isspace(**str))
        (*str)++;
    
    // Si el string está vacío, retorna -1
    if (**str == 0)
        return -1;
    
    // Convierte el string a número usando strtol
    char *endptr;
    int64_t nb = strtol(*str, &endptr, 10);
    
    // Verifica errores de conversión
    // - Si endptr es igual al inicio, no se leyó ningún dígito
    // - Si nb < 0, el número es negativo (no permitido)
    // - Si *endptr != 0, hay caracteres extra después del número
    // - Si nb > UINT32_MAX, el número es demasiado grande para uint32_t
    if (endptr == *str || nb < 0 || (*endptr != 0 && !isspace(*endptr)) || (unsigned long long)nb > (unsigned long long)UINT32_MAX)
        throw std::runtime_error("Invalid input");
    
    // Actualiza el puntero al siguiente número
    *str = endptr;
    return nb;
}

// Crea una lista de enteros sin signo desde un array de strings
std::vector<uint32_t> create_list(char **str) {
    std::vector<uint32_t> res;

    while (*str) {
        res.push_back(getNextNumber((char **)str));
        str++;
    }
    return res;
}

// ========== FUNCIONES DE ORDENAMIENTO ==========

// Inicializa pares de números para el algoritmo merge-insert sort usando vector
// Crea pares de números adyacentes, asegurando que el mayor está en first (primera posición)
// Si hay un número impar de elementos, marca odd_pair como true y guarda el último elemento
static void init_merge_pair(const std::vector<uint32_t> &input, pair_vector_u32_t &res_vector,
                            bool &odd_pair) {
    odd_pair = false;

    // Crea pares de elementos adyacentes (índices 0-1, 2-3, 4-5, etc.)
    for (size_t i = 0; i < input.size() - 1; i += 2) {
        int64_t n1 = input[i];
        int64_t n2 = input[i + 1];

        // Si n2 > n1, los intercambia para que el mayor esté en first
        // Esto es necesario para el algoritmo Ford-Johnson
        if (n2 > n1) {
            std::swap(n1, n2);
        }
        // Crea un par con el mayor en first y el menor en second
        res_vector.push_back(std::make_pair(static_cast<uint32_t>(n1), static_cast<uint32_t>(n2)));
    }
    // Si hay un número impar de elementos, marca odd_pair y guarda el último elemento
    if (input.size() % 2) {
        odd_pair = true;
        // Usa -1 como marcador en first para indicar que este par es especial (solo tiene second)
        res_vector.push_back(
            std::make_pair(static_cast<uint32_t>(-1), static_cast<uint32_t>(input.back())));
    }
}

// Compara dos pares por su primer elemento (first)
// Usado para ordenar los pares según el elemento mayor de cada par
bool compareByFirst(const std::pair<uint32_t, uint32_t> &a,
                    const std::pair<uint32_t, uint32_t> &b) {
    return a.first < b.first;
}

// Función auxiliar de merge para merge sort: fusiona dos mitades ordenadas
// left: inicio del rango a fusionar
// mid: punto medio (fin de la primera mitad, inicio de la segunda)
// right: fin del rango a fusionar
void merge(pair_vector_u32_t &vec, size_t left, size_t mid, size_t right) {
    pair_vector_u32_t temp;		// Vector temporal para almacenar el resultado fusionado
    size_t            i = left, j = mid + 1;	// Índices para recorrer las dos mitades

    // Fusiona las dos mitades mientras ambas tengan elementos
    while (i <= mid && j <= right) {
        // Compara los primeros elementos de cada mitad y coloca el menor en temp
        if (compareByFirst(vec[i], vec[j])) {
            temp.push_back(vec[i++]);
        } else {
            temp.push_back(vec[j++]);
        }
    }
    // Copia los elementos restantes de la primera mitad (si los hay)
    while (i <= mid)
        temp.push_back(vec[i++]);
    // Copia los elementos restantes de la segunda mitad (si los hay)
    while (j <= right)
        temp.push_back(vec[j++]);

    // Copia el resultado fusionado de vuelta al vector original
    for (size_t k = 0; k < temp.size(); ++k) {
        vec[left + k] = temp[k];
    }
}

// Ordena pares usando merge sort recursivo (algoritmo divide y vencerás)
// left: índice del primer elemento del rango
// right: índice del último elemento del rango
void merge_sort_pair(pair_vector_u32_t &vec, size_t left, size_t right) {
    // Caso base: si left >= right, el subarray tiene 0 o 1 elementos (ya está ordenado)
    if (left >= right)
        return;

    // Calcula el punto medio del rango
    size_t mid = left + (right - left) / 2;

    // Ordena recursivamente la primera mitad (left a mid)
    merge_sort_pair(vec, left, mid);
    // Ordena recursivamente la segunda mitad (mid+1 a right)
    merge_sort_pair(vec, mid + 1, right);

    // Fusiona las dos mitades ordenadas
    merge(vec, left, mid, right);
}

// Inserta un valor en el vector manteniendo el orden usando búsqueda binaria
// Busca la posición correcta usando búsqueda binaria y luego inserta el valor
void insertion(std::vector<uint32_t> &arr, uint32_t value) {
    int left = 0;
    int right = arr.size() - 1;
    int pos = arr.size();  // Posición donde insertar (por defecto al final)

    // Búsqueda binaria para encontrar la posición correcta de inserción
    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (arr[mid] < value) {
            // Si el valor del medio es menor, busca en la mitad derecha
            left = mid + 1;
        } else {
            // Si el valor del medio es mayor o igual, la posición está en la mitad izquierda
            pos = mid;
            right = mid - 1;
        }
    }

    // Inserta el valor en la posición encontrada
    // Redimensiona el vector agregando un elemento al final
    arr.push_back(0);
    // Mueve los elementos desde pos hacia la derecha para hacer espacio
    // memmove copia los bytes desde pos hasta el final
    std::memmove(&arr[pos + 1], &arr[pos], (arr.size() - pos - 1) * sizeof(int));
    // Inserta el nuevo valor en la posición correcta
    arr[pos] = value;
}

// Genera la secuencia de Jacobsthal hasta un índice máximo
// La secuencia de Jacobsthal usada en Ford-Johnson es: 1, 3, 5, 11, 21, 43, 85, ...
// Se calcula como: j[0] = 1, j[n] = j[n-1] + 2*j[n-2] para n >= 2
// Se usa en el algoritmo de Ford-Johnson para determinar el orden de inserción
static std::vector<size_t> generate_jacobsthal(size_t max_index) {
    std::vector<size_t> jacob;
    if (max_index == 0) return jacob;
    
    jacob.push_back(1);  // j[0] = 1 (primer número de Jacobsthal)
    
    // Genera números de Jacobsthal hasta que sean mayores que max_index
    // Fórmula: j[n] = j[n-1] + 2*j[n-2] (pero la secuencia real es: 1, 3, 5, 11, 21, 43, ...)
    size_t j_prev = 1;
    size_t j_curr = 3;
    
    while (j_curr <= max_index) {
        jacob.push_back(j_curr);
        size_t next = j_curr + 2 * j_prev;
        j_prev = j_curr;
        j_curr = next;
    }
    
    return jacob;
}

// Genera el orden de inserción basado en la secuencia de Jacobsthal
// Este es el orden correcto según el algoritmo de Ford-Johnson (merge-insert sort)
// El orden optimiza el número de comparaciones al insertar los elementos menores
static std::vector<size_t> generate_insertion_order(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;
    
    // El primer elemento (índice 0) siempre se inserta primero
    // Esto es porque es el primer elemento "menor" que no tiene "mayor" asociado todavía
    order.push_back(0);
    
    // Si solo hay un elemento, ya está completo
    if (n == 1) return order;
    
    // Genera la secuencia de Jacobsthal
    std::vector<size_t> jacob = generate_jacobsthal(n);
    
    // Crea un vector de booleanos para rastrear qué índices ya se han agregado
    std::vector<bool> used(n, false);
    used[0] = true;
    
    // Para cada número de Jacobsthal en la secuencia, inserta los índices en orden
    // El orden es: primero los índices en el rango anterior al número de Jacobsthal
    for (size_t idx = 0; idx < jacob.size(); idx++) {
        size_t jacob_num = jacob[idx];
        
        // Determina el rango de índices a procesar
        size_t start = (idx == 0) ? 1 : jacob[idx-1] + 1;
        size_t end = (jacob_num < n) ? jacob_num : n;
        
        // Inserta los índices en orden descendente (del más grande al más pequeño)
        // Esto minimiza las comparaciones en la búsqueda binaria
        for (size_t j = end; j > start; j--) {
            size_t pos = j - 1;
            if (pos < n && !used[pos]) {
                order.push_back(pos);
                used[pos] = true;
            }
        }
        
        // Si el número de Jacobsthal es menor que n, procesa el último del grupo
        if (jacob_num - 1 < n && !used[jacob_num - 1]) {
            order.push_back(jacob_num - 1);
            used[jacob_num - 1] = true;
        }
    }
    
    // Agrega los índices restantes que no fueron cubiertos por la secuencia de Jacobsthal
    // Estos se insertan en orden secuencial al final
    for (size_t i = 0; i < n; i++) {
        if (!used[i]) {
            order.push_back(i);
        }
    }
    
    return order;
}


// Implementación del algoritmo merge-insert sort usando vector
// str: array de strings con los números a ordenar
// Mide el tiempo de ejecución del algoritmo completo
void pmergeme_vector(char **str) {
    pair_vector_u32_t pair_vector;	// Vector para almacenar pares de números
    bool              odd = false;	// Indica si hay un número impar de elementos

    // Crea la lista de números desde los argumentos de línea de comandos
    std::vector<uint32_t> start = create_list(str);

    // Caso especial: si hay menos de 2 elementos, no hay nada que ordenar
    if (start.size() < 2) {
        if (start.size() == 1) {
            // Si hay un solo elemento, ya está ordenado (tiempo = 0)
            std::vector<uint32_t> res(1);
            res[0] = start[0];
            double merge_time = 0;
            double insert_time = 0;
            print_res(start, res, merge_time, insert_time);
        }
        return;
    }

    // Inicializa los pares para el merge sort (crea pares con mayor en first)
    init_merge_pair(start, pair_vector, odd);

    // Calcula el tamaño sin contar el par impar si existe
    // El par impar tiene first = -1, así que no cuenta para el ordenamiento
    size_t size = pair_vector.size() - (odd == true);

    // Verifica que haya al menos un par válido para ordenar
    if (size == 0) {
        return;
    }

    // Mide el tiempo de ejecución del merge sort (ordena los pares por su elemento mayor)
    TIME(merge_time, merge_sort_pair(pair_vector, 0, size - 1);)

    // Inicializa el vector resultado con los primeros elementos de cada par (los "mayores")
    std::vector<uint32_t> res(size);

	// Mide el tiempo de ejecución de la fase de inserción
	TIME(insert_time,
    // Copia los primeros elementos de cada par (ya ordenados por merge sort)
    // Estos son los elementos "mayores" de cada par que ya están en orden
    for (size_t i = 0; i < size; i++) {
        res[i] = pair_vector[i].first;
    }

    // Genera el orden de inserción usando la secuencia de Jacobsthal (algoritmo de Ford-Johnson)
    // Este orden minimiza el número de comparaciones al insertar los elementos "menores" (second)
    std::vector<size_t> insertion_order = generate_insertion_order(size);
    
    // Inserta los segundos elementos en el orden determinado por la secuencia de Jacobsthal
    // Este orden optimizado reduce el número de comparaciones necesarias
    for (size_t i = 0; i < insertion_order.size(); i++) {
        size_t index = insertion_order[i];
        if (index < size) {
            insertion(res, pair_vector[index].second);
        }
    }

    // Si hay un elemento impar (no tiene par), lo inserta al final
    if (odd == true) {
        insertion(res, pair_vector[size].second);
    })

	// Imprime los resultados (antes, después, tiempos de ejecución)
	print_res(start, res, merge_time, insert_time);

}

// ========== IMPLEMENTACIÓN DE FUNCIONES AUXILIARES PARA DEQUE ==========

// Inicializa pares para merge sort usando deque (similar a init_merge_pair pero con deque)
// Crea pares de números adyacentes, asegurando que el mayor está en first
// Si hay un número impar de elementos, marca odd_pair como true y guarda el último elemento
void init_merge_pair_deque(const std::vector<uint32_t> &input, pair_deque_u32_t &res_deque,
                            bool &odd_pair) {
    odd_pair = false;

    // Crea pares de elementos adyacentes (índices 0-1, 2-3, 4-5, etc.)
    for (size_t i = 0; i < input.size() - 1; i += 2) {
        int64_t n1 = input[i];
        int64_t n2 = input[i + 1];

        // Si n2 > n1, los intercambia para que el mayor esté en first
        // Esto es necesario para el algoritmo Ford-Johnson
        if (n2 > n1) {
            std::swap(n1, n2);
        }
        // Crea un par con el mayor en first y el menor en second, y lo agrega al deque
        res_deque.push_back(std::make_pair(static_cast<uint32_t>(n1), static_cast<uint32_t>(n2)));
    }
    // Si hay un número impar de elementos, marca odd_pair y guarda el último elemento
    if (input.size() % 2) {
        odd_pair = true;
        // Usa -1 como marcador en first para indicar que este par es especial (solo tiene second)
        res_deque.push_back(
            std::make_pair(static_cast<uint32_t>(-1), static_cast<uint32_t>(input.back())));
    }
}

// Compara dos pares por su primer elemento (first)
// Usado para ordenar los pares según el elemento mayor de cada par
bool compareByFirstDeque(const std::pair<uint32_t, uint32_t> &a,
                         const std::pair<uint32_t, uint32_t> &b) {
    return a.first < b.first;
}

// Función auxiliar de merge para merge sort con deque: fusiona dos mitades ordenadas
// deq: deque que contiene los pares a fusionar
// left: inicio del rango a fusionar
// mid: punto medio (fin de la primera mitad, inicio de la segunda)
// right: fin del rango a fusionar
void merge_deque(pair_deque_u32_t &deq, size_t left, size_t mid, size_t right) {
    pair_deque_u32_t temp;		// Deque temporal para almacenar el resultado fusionado
    size_t            i = left, j = mid + 1;	// Índices para recorrer las dos mitades

    // Fusiona las dos mitades mientras ambas tengan elementos
    while (i <= mid && j <= right) {
        // Compara los primeros elementos de cada mitad y coloca el menor en temp
        if (compareByFirstDeque(deq[i], deq[j])) {
            temp.push_back(deq[i++]);
        } else {
            temp.push_back(deq[j++]);
        }
    }
    // Copia los elementos restantes de la primera mitad (si los hay)
    while (i <= mid)
        temp.push_back(deq[i++]);
    // Copia los elementos restantes de la segunda mitad (si los hay)
    while (j <= right)
        temp.push_back(deq[j++]);

    // Copia el resultado fusionado de vuelta al deque original
    for (size_t k = 0; k < temp.size(); ++k) {
        deq[left + k] = temp[k];
    }
}

// Ordena pares usando merge sort recursivo (algoritmo divide y vencerás)
// vec: deque que contiene los pares a ordenar
// left: índice del primer elemento del rango
// right: índice del último elemento del rango
void merge_sort_pair_deque(pair_deque_u32_t &vec, size_t left, size_t right) {
    // Caso base: si left >= right, el subarray tiene 0 o 1 elementos (ya está ordenado)
    if (left >= right)
        return;

    // Calcula el punto medio del rango
    size_t mid = left + (right - left) / 2;

    // Ordena recursivamente la primera mitad (left a mid)
    merge_sort_pair_deque(vec, left, mid);
    // Ordena recursivamente la segunda mitad (mid+1 a right)
    merge_sort_pair_deque(vec, mid + 1, right);

    // Fusiona las dos mitades ordenadas
    merge_deque(vec, left, mid, right);
}

// Inserta un valor en el deque manteniendo el orden usando inserción binaria
// arr: deque ordenado donde insertar el valor
// value: valor a insertar
// Busca la posición correcta usando búsqueda binaria y luego inserta el valor
void insertion_deque(std::deque<uint32_t> &arr, uint32_t value) {
    int left = 0;
    int right = arr.size() - 1;
    int pos = arr.size();  // Posición donde insertar (por defecto al final)

    // Búsqueda binaria para encontrar la posición correcta de inserción
    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (arr[mid] < value) {
            // Si el valor del medio es menor, busca en la mitad derecha
            left = mid + 1;
        } else {
            // Si el valor del medio es mayor o igual, la posición está en la mitad izquierda
            pos = mid;
            right = mid - 1;
        }
    }

    // Inserta el valor en la posición encontrada
    // Inserta un elemento al final para redimensionar el deque
    arr.push_back(0);
    // Mueve los elementos desde pos hacia la derecha para hacer espacio
    // Itera desde el penúltimo elemento hasta pos, moviendo cada elemento una posición a la derecha
    for (int i = arr.size() - 2; i >= pos; --i) {
        arr[i + 1] = arr[i];
    }
    // Inserta el nuevo valor en la posición correcta
    arr[pos] = value;
}

// Implementación completa del algoritmo merge-insert sort usando deque
// str: array de strings con los números a ordenar
// Mide el tiempo de ejecución y compara con la implementación usando vector
void pmergeme_deque(char **str) {
    pair_deque_u32_t pair_deque;	// Deque para almacenar pares de números
    bool              odd = false;	// Indica si hay un número impar de elementos

    // Crea la lista de números desde los argumentos de línea de comandos
    std::vector<uint32_t> start = create_list(str);

    // Caso especial: si hay menos de 2 elementos, no hay nada que ordenar
    if (start.size() < 2) {
        if (start.size() == 1) {
            // Si hay un solo elemento, ya está ordenado (tiempo = 0)
            std::deque<uint32_t> res(1);
            res[0] = start[0];
            double merge_time = 0;
            double insert_time = 0;
            print_res_deque(start, res, merge_time, insert_time);
        }
        return;
    }

    // Inicializa los pares para el merge sort (crea pares con mayor en first)
    init_merge_pair_deque(start, pair_deque, odd);

    // Calcula el tamaño sin contar el par impar si existe
    // El par impar tiene first = -1, así que no cuenta para el ordenamiento
    size_t size = pair_deque.size() - (odd == true);

    // Verifica que haya al menos un par válido para ordenar
    if (size == 0) {
        return;
    }

    // Mide el tiempo de ejecución del merge sort
    TIME(merge_time, merge_sort_pair_deque(pair_deque, 0, size - 1);)

    // Inicializa el deque resultado con los primeros elementos de cada par (los "mayores")
    std::deque<uint32_t> res(size);

    // Mide el tiempo de ejecución de la fase de inserción
    TIME(insert_time,
    // Copia los primeros elementos de cada par (ya ordenados por merge sort)
    // Estos son los elementos "mayores" de cada par que ya están en orden
    for (size_t i = 0; i < size; i++) {
        res[i] = pair_deque[i].first;
    }

    // Genera el orden de inserción usando la secuencia de Jacobsthal (algoritmo de Ford-Johnson)
    // Este orden minimiza el número de comparaciones al insertar los elementos "menores" (second)
    std::vector<size_t> insertion_order = generate_insertion_order(size);
    
    // Inserta los segundos elementos en el orden determinado por la secuencia de Jacobsthal
    // Este orden optimizado reduce el número de comparaciones necesarias
    for (size_t i = 0; i < insertion_order.size(); i++) {
        size_t index = insertion_order[i];
        if (index < size) {
            insertion_deque(res, pair_deque[index].second);
        }
    }

    // Si hay un elemento impar (no tiene par), lo inserta al final
    if (odd == true) {
        insertion_deque(res, pair_deque[size].second);
    })

    // Imprime los resultados (antes, después, tiempos de ejecución)
    print_res_deque(start, res, merge_time, insert_time);
}

// ========== FUNCIONES DE IMPRESIÓN ==========

// Imprime un vector de enteros sin signo separados por espacios
// vec: vector con los números a imprimir
static void print_vec(const std::vector<uint32_t> &vec) {
    size_t size = vec.size();

    // Itera sobre todos los elementos del vector
    for (size_t i = 0; i < size; i++) {
        std::cout << vec[i];
        // Imprime un espacio entre elementos (excepto después del último)
        if (i < size - 1)
            std::cout << " ";
    }
}

// Imprime los resultados comparando tiempos de ejecución usando std::vector
// start: vector con los números originales (antes de ordenar)
// res: vector con los números ordenados (después de ordenar)
// merge_time: tiempo de ejecución del merge sort en microsegundos
// insert_time: tiempo de ejecución de la fase de inserción en microsegundos
void print_res(const std::vector<uint32_t> &start,
				const std::vector<uint32_t> &res,
				double merge_time,
				double insert_time) {

    // Imprime la lista original (antes de ordenar)
    std::cout << "Before: ";
    print_vec(start);
    std::cout << std::endl;

    // Imprime la lista ordenada (después de ordenar)
    std::cout << "After:  ";
    print_vec(res);
    std::cout << std::endl;

    // Imprime el tiempo total de ejecución (merge + inserción) en microsegundos
    std::cout << "Time to process a range of " << res.size()
              << " elements with std::vector: " << merge_time + insert_time << " us" << std::endl;
}

// Imprime los resultados para deque (solo tiempo, no imprime la lista porque ya se imprimió con vector)
// start: vector con los números originales (no usado, solo para mantener la firma)
// res: deque con los números ordenados (para obtener el tamaño)
// merge_time: tiempo de ejecución del merge sort en microsegundos
// insert_time: tiempo de ejecución de la fase de inserción en microsegundos
void print_res_deque(const std::vector<uint32_t> &start,
                     const std::deque<uint32_t> &res,
                     double merge_time,
                     double insert_time) {
    (void)start; // Suprime el warning de parámetro no usado (se mantiene para consistencia con print_res)

    // Imprime el tiempo total de ejecución (merge + inserción) en microsegundos
    std::cout << "Time to process a range of " << res.size()
              << " elements with std::deque: " << merge_time + insert_time << " us" << std::endl;
}
