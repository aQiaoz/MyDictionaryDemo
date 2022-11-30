#include <iostream>
using namespace std;

int main()
{
    int n;
    int *p=(int*)malloc(sizeof(int));
    
    cout<<"Please enter a number which is greater than 2:";
    cin>>n;
    p[0]=1;
    p[1]=1;
    for(int i=2;i<=n-1;i++)
    {
       p[i]=p[i-1]+p[i-2];
    }
    
    for(int j=0;j<n;j++)
    {
        cout<<p[j]<<'\t';
        if((j+1)%5==0)
          cout<<endl;
    }
    free(p);
    return  0;
}