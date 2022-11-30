//这篇问了老师哦
#include <iostream>
#include <iomanip>
using namespace::std;
class PartFilledArray
{    
    friend ostream& operator<<(ostream& out,PartFilledArray &p);
    public:    
        PartFilledArray(int array_size);    
        PartFilledArray(const PartFilledArray & object);    
        ~PartFilledArray( );    
        void addValue(double newentry);
    
    protected:    
        double *a;    
        int max_number;    
        int number_used;
};

PartFilledArray::PartFilledArray(int array_size)
{
    max_number=(array_size > 0 ? array_size : 10);
    a=new double [max_number];
    for(int i=0;i<max_number;i++)
    {
        a[i]=0;
    }
    number_used=0;
}

PartFilledArray::PartFilledArray(const PartFilledArray & object):max_number(object.max_number)
{
    a=new double[max_number];
    number_used=object.number_used;   //这一步很重要，头次忘了写
    for(int i=0;i<object.number_used;i++)
    {
        a[i]=object.a[i];
    }
}

void PartFilledArray::addValue(double newentry)
{
    a[number_used]=newentry;
    number_used++;
    while(number_used>max_number)
    { 
        cout<<"Adding to a full array."<<endl;
        exit(1);
    }  
}


ostream& operator<<(ostream& output,PartFilledArray &p)
{
    int i;
    for(i=0;i<p.number_used;i++)
    {
        output<<setw(2)<<p.a[i];
    }
    return output;
}
PartFilledArray::~PartFilledArray()
{
    delete [] a;
}


int main()
{    
    PartFilledArray a(7);    
    double x;    
    cin>>x;    
    while (x!=0) 
    {        
        a.addValue(x);        
        cin>>x;    
    }    
    cout<<a;    
    PartFilledArray b(a);    
    cout<<b;
}