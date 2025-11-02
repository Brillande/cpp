#pragma once

#include <stack>
#include <iostream>

// Plantilla de clase: stack con capacidad de iteración
// std::stack no tiene iteradores, pero internamente usa un contenedor (por defecto deque)
// Esta clase hereda de std::stack y expone los iteradores del contenedor interno
template <typename T>
class MutantStack : public std::stack<T> 
{
    public:
        // Constructor por defecto: crea un MutantStack vacío
        MutantStack() 
        {
            std::cout << "constructor MutantStack<T> empty" << std::endl;
        }

        // Constructor de copia: crea una copia del MutantStack
        MutantStack(const MutantStack &src) : std::stack<T>(src) 
        {
            std::cout << "constructor MutantStack copy" << std::endl;
        }

        // Destructor: libera los recursos
        ~MutantStack() 
        {
            std::cout << "destructor MutantStack" << std::endl;
        }

        // Operador de asignación: copia el contenido del MutantStack
        MutantStack &operator=(const MutantStack &src) 
        {
            if (this != &src) 
            {
                // Llama al operador de asignación de la clase base (std::stack)
                std::stack<T>::operator=(src);
            }
            return *this;
        }

        // Define tipos de iteradores: expone los iteradores del contenedor interno
        // std::stack<T>::container_type es el tipo del contenedor subyacente (por defecto deque)
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        // Retorna un iterador al primer elemento del contenedor interno
        // 'c' es el miembro protegido que contiene el contenedor interno del stack
        iterator begin()
        { 
            return std::stack<T>::c.begin();
        }
        
        // Retorna un iterador al elemento después del último (end)
        iterator end()
        {
            return std::stack<T>::c.end();
        }

        // Versiones const de los iteradores (para objetos constantes)
        const_iterator begin() const
        {
            return std::stack<T>::c.begin();
        }
        const_iterator end() const 
        {
            return std::stack<T>::c.end();
        }
};
