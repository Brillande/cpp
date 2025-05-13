#include "EasyFind.hpp"

int main() 
{
    std::vector<int> numbers;
    for (int i = 0; i < 10; ++i)
        numbers.push_back(i * 2); // 0, 2, 4, ..., 18

    try 
    {
        int *found = easyfind(numbers, 8);
        std::cout << "Encontrado: " << *found << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "No encontrado: 8" << std::endl;
    }

    try 
    {
        int *found = easyfind(numbers, 7);
        std::cout << "Encontrado: " << *found << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cout << "No encontrado: 7" << std::endl;
    }

    return 0;
}