#include <iostream>
using namespace std;
#include <stdexcept>

void f2(int a, int b )
{
    cout<<"In f2 function"<<endl;
    throw "string";
}
void f1(int a, int b)
{
    float c;
    try
    {
        f2(a,b);
    }
    catch(const char* e)
    {
        cout<<"Exception from f2"<<endl;
    }
    if(b==0)
    {
        throw b;
    }
    c=a%b;
    cout<<a<<"%"<<b<<"="<<a%b<<endl;
    cout<<"In f1 function"<<endl;
}
int main()
{
    try
    {
        float a,b;
        cin>>a>>b;
        if((a-int(a))!=0)
        {
            throw a;
        }
        if((b-int(b))!=0)
        {
            throw b;
        }
        f1(a,b);
    }
    catch(const int err)
    {
        cout<<"You inputted:0"<<endl;
    }
    catch(const float e)
    {
        cout<<"Non-int was inputted, try again"<<endl;
    }
    cout<<"In main function"<<endl;
    return 0;
}