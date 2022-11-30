////模板
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template <class T>
void swp(T &x, T &y) //传参类型一致
{
    T temp=x;
    x=y;
    y=temp;
}
template <class T1, class T2>
void swp1(T1 &x, T2 &y) //传参类型不一致，可以避免二义性
{
    T1 temp=x;
    x=y;
    y=temp;
}
int main()
{
    char a='A', b='B';
    int c=123, d=456;
    double e=12.3, f=45.6;
    swp(a,b);
    swp(c,d);
    swp(e,f);
    swp1(c,f);
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
}

////模板函数覆盖  
//如果某一函数的函数原型与函数模板生成的函数（模板函数）原型一致，称该函数为模板函数的覆盖函数。
template <class T>
T max1(T a,T b)
{
    return a>b ? a:b;
}
char *max(char *x, char *y)
{
    return strcmp(x,y)>0 ? x:y;
}
int main()
{
    char *p="ABCD", *q="EDGF";
    p=max1(p,q);
    int a = max1(10,20);
    float b = max1(12.3,45.6);
    cout << p << endl;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
//模板函数重载
template<class T>
T myFunction( T arg)
{ 
    cout<< "one argument\n"; return arg1;}
template<class T1, class T2>
T1 myFunction( T1 arg1, T2 arg2)
{ cout<< "two arguments\n"; return arg1;}
//......
//myFunction( 5); //ok ： replace with int
//myFunction( 5.8, 8.4); //ok： replace T1 and T2 with double
//myFunction( 5, 8.4); //ok： replace T1 with int, T2 with double

////由于不同编译器在处理模板时方法不同，为了程序能在更多的编译器上运行，请将函数模板定义和调用模板的程序放在同一个文件中，并且把模板定义放在调用模板之前。


//类模板
const int size=50;
template <class T>
class Array
{
    T x[50];
    public:
        Array();
        void input( int n );
        void print( int n );
        T max( int n );
        void sort( int n);
};
template <class T>
Array<T>::Array()
{
    int i;
    for(i=0;i<size;i++)
        x[i]=0;
}
template <class T>
void Array<T>::input( int n )
{
    int i;
    for(i=o;i<n;i++)
    {
        cout<<"x["<<i<<"]";
        cin>>x[i];
    }
}
template <class T>
void Array<T>::print( int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<x[i]<<" ";
        cout<<endl;
}
int main()
{
    int n;
    Array <int> ob1;
    cin>>n;
    ob1.input(n);
    ob1.print(n);
    Array <float> ob2;
    cin>>n;
    ob2.input(n);
    ob2.print(n);
}

////类模板与继承
template <class T, int size>
class base
{
    protected:
    T elements[size];
    public:
    void setBaseElement(T arg, int index);};
template <class T, int size>
void base<T,size>::setBaseElement(T arg, int index)
{elements[index] = arg;  }

template <class T> 
class son:public base<string, 5>
{
    T elements[5];
    public:
    void setSonElement(T arg, int index);
    void printElement(int index);};
template <class T>void son<T>::setSonElement(T arg, int index)
{
    elements[index] = arg;return; 
}
template <class T>void son<T>::printElement(int index)
{
    cout<<base<string, 5>::elements[index] <<"   ";
    cout<<elements[index] <<endl;
    return;
}
son<int> sonObj;

//类模板从普通类派生
