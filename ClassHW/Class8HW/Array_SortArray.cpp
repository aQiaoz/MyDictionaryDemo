#include <iostream>
#include <iomanip>
using namespace std;
class Array
{
    public: Array( int ); // default constructor 
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

class SortArray:public Array
{
    public:
        SortArray( int siz1 ):Array(siz1)
        {
            isSort=false;
        }
        void input()
        { Array::input(); }
        void Sort()
        {
            int temp=0;
            for(int i=0;i<size-1;i++)
            {
                for(int j=0;j<size-i-1;j++)
                {
                    if(ptr[j]>ptr[j+1])
                    {
                        temp=ptr[j];
                        ptr[j]=ptr[j+1];
                        ptr[j+1]=temp;
                    }
                }
            }
            isSort=true;
        }
        void display()
        { Array::display(); }
    protected:
        bool isSort;
};



int main()
{    
    SortArray integers1( 7 );   

    integers1.input ();    
    cout<<"Integers1:"<<endl;    
    cout<<"Before sort:"<<endl;    
    integers1.display ();
    cout<<endl;    
    cout<<"After sort:"<<endl;    
    integers1.Sort();    
    integers1.display ();    
    return 0;
}
