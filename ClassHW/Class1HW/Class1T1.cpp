#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cin>>x;
    cin>>y;

    cout<<"x|\t";
    for(int j=0;j<=y;j++)
    {
        cout<<j<<'\t';
    }
    cout<<endl;
    for(int i=0;i<=y;i++)
    {
        cout.fill('-');
        cout.width(2*y);
        cout<<'-';
    }
    cout<<endl;

    for(int i=0;i<=x;i++)
    {
        cout<<i<<'|'<<'\t';
        for(int j=0;j<=y;j++)
        {
           cout<<i*j<<'\t';
        }
        cout<<endl;
    }
    return 0;
}

