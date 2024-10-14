using namespace std;

#include <iostream>

using namespace std;

int main() {
    string myString = "HI THIS IS BRAIN";
    string *stringPTR = &myString;

    string &stringREF = myString;

    cout << "Address of myString: " << &myString << endl;
    cout << "Address of stringPTR: " << stringPTR << endl;
    cout << "Address of stringREF: " << &stringREF << endl;

    cout << endl;

    cout << "Value of myString: " << myString << endl;
    cout << "Value pointed to by stringPTR: " << *stringPTR << endl;
    cout << "Value of stringREF: " << stringREF << endl;

    return 0;
}