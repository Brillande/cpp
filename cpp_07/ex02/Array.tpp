/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:54:18 by emedina-          #+#    #+#             */
/*   Updated: 2025/05/07 13:30:03 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Retorna el tamaño del array (número de elementos)
template<typename T>
unsigned int Array<T>::size() const
{
	return (n);
}

// Constructor por defecto: crea un array vacío
template<typename T>
Array<T>::Array() : array(NULL), n(0)
{
	// Inicializa el puntero a NULL y el tamaño a 0
	return ;
}

// Constructor con tamaño: crea un array de n elementos inicializados
template<typename T>
Array<T>::Array(unsigned int n)
{
	this->n = n;				// Guarda el tamaño
	array = new T[n];			// Asigna memoria para n elementos de tipo T
	// Inicializa todos los elementos con el constructor por defecto de T
	for (unsigned int i = 0; i < n; i++)
		array[i] = T();		// Llama al constructor por defecto de T para cada elemento
	return ;
}

// Constructor de copia: crea una copia profunda del array
template<typename T>
Array<T>::Array(Array<T> const &src) : n(src.n)
{
	// Asigna memoria para el mismo número de elementos que src
	array = new T[n];
	// Copia cada elemento del array original
	for (unsigned int i = 0; i < n; i++)
		array[i] = src.array[i];
	return ;
}

// Operador de asignación: copia el contenido del array asignado
template<typename T>
Array<T>& Array<T>::operator=(Array<T> const &assign)
{
	// Libera la memoria del array actual antes de asignar uno nuevo
	delete[] this->array;
	// Actualiza el tamaño con el del array asignado
	n = assign.n;
	// Asigna memoria para el nuevo tamaño
	array = new T[n];
	// Copia cada elemento del array asignado
	for (unsigned int i = 0; i < n; i++)
		array[i] = assign.array[i];
	return (*this);
}

// Operador de índice: permite acceder a elementos del array con verificación de límites
template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	// Verifica que el índice esté dentro de los límites del array (0 a n-1)
	if (index > this->n - 1)
		throw Array::OutOfBoundsException();	// Lanza excepción si está fuera de límites
	return (array[index]);	// Retorna una referencia al elemento en el índice solicitado
}

// Destructor: libera la memoria del array
template<typename T>
Array<T>::~Array()
{
	// Libera la memoria asignada dinámicamente con new[]
	delete [] array;
	return ;
}
