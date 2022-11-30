#include<iostream>
using namespace std;
class Cargo
{
    public:    
        Cargo(int ,int);    
        void total();
    private:    
        int cartons;    
        int items;
};
Cargo::Cargo(int it,int ca):items(it),cartons(ca){}
void Cargo::total()
{    
        cout<<"The total number of items is "
    <<items*cartons<<endl;
}

int main()
{
    Cargo *p;
    Cargo a[5]={Cargo(1,10),Cargo(2,20),Cargo(3,30),Cargo(4,40),Cargo(5,50)};
    p=a;
    for(int i=4;i>=0;i--)
    {
        p[i].total();
    }
    delete[] p,a;
}

