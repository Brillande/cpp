#include "Span.hpp"
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "imprime la menor diferencia entre dos numeros " << sp.shortestSpan() << std::endl;
    std::cout <<"imprime la mayor diferencia entre dos numeros " << sp.longestSpan() << std::endl;
    return 0;
}