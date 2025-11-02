#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    mstack.push(30);
    mstack.push(5);
    std::cout << "we see the first element " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "we delete the last element " << std::endl;
    std::cout << "we see the size of stack " << mstack.size() << std::endl;
    std:: cout << "we add more elements " << std::endl;
    mstack.push(50);
    mstack.push(80);
    mstack.push(90);
    mstack.push(-1);
    MutantStack<int>::iterator i = mstack.begin();
    MutantStack<int>::iterator x = mstack.end();
    std::cout << "whith this while we can see all the elements of the stack" << std::endl;
    while (i != x)
    {
        std::cout << *i << std::endl;
        ++i;
    }
    std::stack<int> s(mstack);
    return 0;
}
