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

template<typename T>
unsigned int Array<T>::size() const
{
	return (n);
}

template<typename T>
Array<T>::Array() : array(NULL), n(0)
{
	return ;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->n = n;
	array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		array[i] = T();
	return ;
}

template<typename T>
Array<T>::Array(Array<T> const &src) : n(src.n)
{
	array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		array[i] = src.array[i];
	return ;
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> const &assign)
{
	delete[] this->array;
	n = assign.n;
	array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		array[i] = assign.array[i];
	return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index > this->n - 1)
		throw Array::OutOfBoundsException();
	return (array[index]);
}

template<typename T>
Array<T>::~Array()
{
	delete [] array;
	return ;
}
