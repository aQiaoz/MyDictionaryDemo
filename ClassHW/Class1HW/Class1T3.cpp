#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int n,i=0,j=0,x=1;
    int *p=new int[10];
    do
    {
        cin>>n;
        p[i]=n;
        i++;
        if(i%10==x)
        {
            int *p=new int[i+10];
            x++;
        }
    }while(n!=0);
   
   for(int m=0;m<i;m++)
   {
      cout<<p[m]<<' ';
   }
    delete p;
    return 0;
}