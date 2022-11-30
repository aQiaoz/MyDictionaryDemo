#include <iostream>
#include <vector>
#include<stack> 
using namespace std;

int main()
{
    stack< int > s;
    int num;
    cin>>num;
    while (num != 0)
    {
        s.push(num % 2);
        num = num / 2;
    }
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}