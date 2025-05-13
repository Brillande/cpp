#include "EasyFind.hpp"

int main() 
{
    std::vector<int> numbers;
    for (int i = 0; i < 10; ++i)
        numbers.push_back(i); // 0, 2, 4, ..., 18

    try 
    {
        int *found = easyfind(numbers, 8);
        std::cout << "finded: " << *found << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "dont finded: 8" << std::endl;
    }

    try 
    {
        int *found = easyfind(numbers, 10);
        std::cout << "finded: " << *found << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cout << "dont finded: 10" << std::endl;
    }

    return 0;
}