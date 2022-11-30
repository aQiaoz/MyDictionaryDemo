#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int num;
    cin>>num;
    vector< int > a,b;
    for (int i=2;i<=num;i++)
    {
        a.push_back(i);
    }

    int flag=0; 
    for(int i=0;i<=a.size();i++)
    {
        flag=0;
        for(int j=0;j+2<=sqrt(i+2);j++)
        {
            if( a[i] % a[j] == 0 )
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            b.push_back(a[i]);
        }
    
    }
    b.pop_back();
    for(int i=0;i<=b.size();i++)
    {
        if( i%10==0 )
        {
            cout<<endl;
        }
        cout<<setw(5)<<b[i];
    }
    
    return 0;
}