#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char a[100];
    int i;
    while(cin>>a)
    {
        stack<char> b;
        for(i = 0;a[i];i++)
        {
            if(a[i] == '(')
                {
                    b.push(a[i]);
                    continue;
                }
            if(a[i]==')')
                {
                    if(b.top()=='(')
                    {
                        b.pop();
                    }
                    continue;
                }
        }
        if(b.empty()==true)
            cout <<"true\n";
        else
            cout <<"false\n";
    }
 
    return 0;
}

