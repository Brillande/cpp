#pragma once
#include <algorithm>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstddef>

// Clase Span: almacena un número limitado de enteros y calcula la diferencia más corta y más larga
class Span
{
    public:
      // Constructores
      Span(const Span &ref);		// Constructor de copia
      Span(size_t size);			// Constructor con tamaño máximo
      ~Span(void);					// Destructor
  
      // Operadores
      Span &operator=(Span const &src);	// Operador de asignación
  
      // Getters
      size_t size(void) const;		// Retorna el tamaño máximo del Span
      size_t index(void) const;		// Retorna el número actual de elementos almacenados
  
      // Métodos para agregar números
      void addNumber(int nb);		// Agrega un número al Span
      void addNumber(std::vector<int>::iterator start,
                     std::vector<int>::iterator end);	// Agrega un rango de números
  
      // Métodos para calcular diferencias
      int shortestSpan(void) const;	// Retorna la diferencia más corta entre dos números
      int longestSpan(void) const;		// Retorna la diferencia más larga (máximo - mínimo)
  
    private:
      Span(void);					// Constructor privado (no se puede crear Span vacío sin tamaño)
      // El vector es como un array dinámico, se puede cambiar su tamaño
      // y se puede acceder a sus elementos como si fuera un array
      std::vector<int> _arr;		// Vector que almacena los números
      const size_t     _size;		// Tamaño máximo del Span (constante)
      size_t           _index;		// Número actual de elementos almacenados
};
  