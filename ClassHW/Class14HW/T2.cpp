#include <iostream>
using namespace std;
int main()
{
    const int SIZE=10;
    char name1[SIZE];
    char name2[SIZE];
    char name3[SIZE];
    char name4[SIZE];
    int n;
    cin.getline(name1,10,'.');
    cout << name1 <<endl;
    cin.putback('.');
    cin.getline(name2,10-cin.gcount());
    cout << name2;
    cin.get();
    cin.getline(name1,10,'.');
    cout << name1 <<endl;
    cin.getline(name2,10);
    cout << name2;

    return 0;
}