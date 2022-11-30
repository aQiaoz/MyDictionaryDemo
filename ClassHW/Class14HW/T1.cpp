#include <iostream>
using namespace std;
int main()
{
    const int SIZE = 100;
    char string[SIZE];
    cin.ignore(5);
    cin.getline(string,100);
    cout << string;
    return 0;
}