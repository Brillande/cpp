#include "Span.hpp"

// Constructor con tamaño: crea un Span con un tamaño máximo específico
Span::Span(size_t size) : _size(size), _index(0) 
{
    std::cout <<  "constructor Span size" << std::endl;
}

// Constructor de copia: crea una copia del Span
Span::Span(const Span &src) : _size(src.size()) 
{
    std::cout <<  "constructor Span copy" << std::endl;
    if (this != &src)
        *this = src;	// Llama al operador de asignación
}

// Destructor: libera los recursos
Span::~Span(void)
{
    std::cout <<  "destructor Span" << std::endl;
}

// Retorna el tamaño máximo del Span
size_t Span::size(void) const 
{
    return _size;
}

// Retorna el número actual de elementos almacenados
size_t Span::index(void) const 
{
    return _index;
}

// Agrega un número al Span
void Span::addNumber(int nb) 
{
	// Verifica si hay espacio disponible
    if (_index >= _size)
		// Se usa runtime_error para reportar errores que ocurren durante la ejecución
		// Por ejemplo: si se intenta añadir un número a un vector que ya está lleno
        throw std::runtime_error("no slot left");
	
	// Agrega el número al vector y aumenta el contador
    _arr.push_back(nb);
	_index++;
}

// Agrega un rango de números desde un iterador inicial hasta uno final
void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	// Calcula cuántos elementos hay en el rango y verifica si hay espacio suficiente
    if (static_cast<size_t>(std::distance(start, end)) > _size - _index)
        throw std::runtime_error("no slot left");
	
	// Inserta todos los elementos del rango al final del vector
    _arr.insert(_arr.end(), start, end);
	// Actualiza el contador con el número de elementos agregados
    _index += std::distance(start, end);
}

// Calcula la diferencia más corta entre dos números del Span
int Span::shortestSpan(void) const
{
	// Si hay menos de 2 elementos, no hay diferencia que calcular
    if (_index <= 1)
        return (0);
    
	// Crea una copia del vector para ordenarlo sin modificar el original
    std::vector<int> sort_arr = _arr;

	// Ordena el vector de menor a mayor
    std::sort(sort_arr.begin(), sort_arr.end());

	// Inicializa el resultado con el máximo valor posible de int
    int result = std::numeric_limits<int>::max();
	
	// Itera sobre el vector ordenado comparando cada elemento con el anterior
    for (std::vector<int>::size_type i = 1; i < sort_arr.size(); ++i) 
    {
		// Calcula la diferencia entre el elemento actual y el anterior
        int tmp = sort_arr[i] - sort_arr[i - 1];
		// Si esta diferencia es menor que la encontrada hasta ahora, la actualiza
        if (tmp < result)
            result = tmp;
    }

    return result;
}

// Calcula la diferencia más larga (máximo - mínimo) del Span
int Span::longestSpan(void) const
{
	// Si hay menos de 2 elementos, no hay diferencia que calcular
    if (_index <= 1)
        return (0);
    
	// Retorna la diferencia entre el elemento máximo y el mínimo
	// max_element y min_element retornan iteradores, se desreferencian para obtener los valores
    return (*std::max_element(_arr.begin(), _arr.end()) -
            *std::min_element(_arr.begin(), _arr.end()));
}

Span &Span::operator=(Span const &origin)
{
    if (this != &origin) {
        _index = origin._index;
        _arr = origin._arr;
    }
    return (*this);
}

Span::Span(void) : _size(0), _index(0)
{
    std::cout <<  "constructor Span empty" << std::endl;
}