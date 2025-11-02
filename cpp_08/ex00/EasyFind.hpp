#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

// Plantilla de función: busca un valor entero dentro de un contenedor genérico
// T: tipo del contenedor (debe tener iteradores begin() y end(), como vector, list, deque, etc.)
// elements: referencia al contenedor donde buscar
// target: valor entero a buscar
// Retorna: puntero al elemento encontrado, o lanza excepción si no se encuentra
template<typename T>
int	*easyfind(T &elements, int target);

#include "EasyFind.tpp"