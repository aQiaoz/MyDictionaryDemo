#include <iostream>
#include <iomanip>
using namespace std;
class Array
{
    public: 
        Array( int ); // default constructor 
        Array( const Array & ); // copy constructor 
        ~Array(); // destructor 
        void input(); //input numbers 
        int getSize() const; // return size 
        void display() const; //display array
    protected: 
        int size; // pointer-based array size 
        int *ptr; // pointer to first element of pointer-based array
}; // end class Array

Array::Array(int siz)
{
    size=(siz>0 ? siz:10);
    ptr=new int [size];
    for(int i=0;i<size;i++)
    {
        ptr[i]=0;
    }
}
Array::Array(const Array &copy):size(copy.size)
{
    ptr=new int [size];
    for(int i=0;i<copy.size;i++)
    {
        ptr[i]=copy.ptr[i];
    }
}
void Array::input()
{
    int size1=0;
    int x;
    while(cin>>x)
    {
        ptr[size1]=x;
        size1++;
        if(size1==size) break;
    }
}
int Array::getSize() const
{
    return size;
}
void Array::display() const
{
    for(int i=0;i<size;i++)
    {
        cout<<setw(5)<<ptr[i];
    }
}
Array::~Array()
{
    delete [] ptr;
}
class AverArray:public Array
{
    public:
        AverArray( int siz1 ):Array(siz1){}
        void input()
        { Array::input(); }
        void aver()
        {
            int av=0;
            for(int i=0;i<size;i++)
            {
                av+=ptr[i];
            }
            average=av/size;
        };
        double getAver() const
        { return average;};
        void display()
        {Array::display();};
    protected:
        double average;  
};

int main()
{    
    AverArray integers1( 7 );    
    integers1.input ();    
    cout<<"Integers1:"<<endl;    
    integers1.display ();    
    integers1.aver ();    
    cout<<fixed<<setprecision(2);    
    cout<<"The average number of integers1 is "<<
    integers1.getAver()<<endl;    
    return 0;
}
