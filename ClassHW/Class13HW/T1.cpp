#include <iostream>
using namespace std;
int main()
{
    float a,b;
    cin>>a>>b;
    try
    {
        if( b==0 )
            throw b;
    }
    catch(float)
    {
        cout<<"Attempted to divide by zero!"<<endl;
    }
    cout<<a/b<<endl;
    cout<<"end"<<endl;
}