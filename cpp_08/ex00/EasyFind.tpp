// Este código se encarga de buscar un int dentro de un contenedor de elementos
// Plantilla de función: busca un valor entero en un contenedor usando std::find
template<typename T>
int	*easyfind(T &elements, int target) 
{
	// Busca el valor target en el contenedor usando std::find del algoritmo STL
	// typename es necesario porque T::iterator es un tipo dependiente del template
	typename T::iterator current = std::find(elements.begin(), elements.end(), target);
	
	// Si el iterador no está en el final del contenedor, el elemento fue encontrado
	if (current != elements.end())
		// Retorna un puntero al elemento encontrado (desreferencia el iterador y toma su dirección)
		return (&(*current));
	else
		// Si no se encuentra, lanza una excepción
        throw std::exception();
}
