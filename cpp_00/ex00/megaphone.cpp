#include <iostream>
using namespace std;

int main(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if(ac < 2)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        while(i < ac)
        {
            j = 0;
            while(av[i][j] != '\0')
            {
                cout << (char)toupper(av[i][j]);
                j++;
            }
            i++;
        }
        cout << "\n";
    }
}