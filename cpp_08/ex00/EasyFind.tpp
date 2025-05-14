//este codigo se encarga de buscar un int dentro de un contenedor de elementos
template<typename T>
int	*easyfind(T &elements, int target) 
{
	typename T::iterator current = elements.begin();

    current = std::find(elements.begin(), elements.end(), target);
	if (current != elements.end())
		return (&(*current));
	else
        throw std::exception();
}
